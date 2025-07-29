%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;          /* integer value */
  double                d;          /* real value */
  size_t               sz;          /* long unsigned int value */
  std::string          *s;          /* symbol name or string literal */
  std::vector<size_t>  *dims;       /* dimensions vector */
  cdk::basic_node      *node;       /* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;

  udf::block_node      *block;
};

%token tTYPE_INT tTYPE_REAL tTYPE_STRING tTYPE_POINTER tTYPE_AUTO tTYPE_VOID tTYPE_TENSOR

%token <i> tINTEGER
%token <d> tREAL
%token <s> tIDENTIFIER tSTRING
%token <expression> tNULLPTR
%token tFOR tIF tELIF tELSE tINPUT tWRITE tWRITELN tSIZEOF tOBJECTS tUNLESS
%token tAND tOR

%token tPUBLIC tPRIVATE tFORWARD
%token tBREAK tCONTINUE tRETURN
%token tCAPACITY tRANK tDIM tDIMS tRESHAPE tCONTRACTION

%type <node>     declaration  argdec  fordec  vardec fundec fundef
%type <sequence> declarations argdecs fordecs vardecs opt_vardecs opt_forinit

%type<s> string
%type<sz>   dim
%type<dims> dims
%type <type> data_type void_type

%nonassoc tIFX
%nonassoc tELIFX
%nonassoc tELIF tELSE

%right '='
%nonassoc '~'
%left tOR
%left tAND
%left   tEQ tNE '<' tLE tGE '>'
%left '+' '-'
%left '*' '/' '%'
%left tCONTRACTION
%nonassoc tUNARY
%nonassoc '.' '@'
%nonassoc '(' '['

%type <node> stmt return iffalse
%type <sequence> file stmts opt_stmts
%type <expression> expr integer real opt_initializer tensor_elem tensor_expr
%type <sequence> exprs opt_exprs tensor_elems
%type <lvalue> lval
%type<block> block

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file         : declarations { compiler->ast($$ = $1); }
             ;

declarations :              declaration { $$ = new cdk::sequence_node(LINE, $1);     }
             | declarations declaration { $$ = new cdk::sequence_node(LINE, $2, $1); }
             ;

declaration  : vardec ';' { $$ = $1; }
             | fundec     { $$ = $1; }
             | fundef     { $$ = $1; }
             ;

vardec : tFORWARD data_type  tIDENTIFIER                 { $$ = new udf::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, nullptr); delete $3; }
       | tPUBLIC  data_type  tIDENTIFIER opt_initializer { $$ = new udf::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, $4); delete $3; }
       |          data_type  tIDENTIFIER opt_initializer { $$ = new udf::variable_declaration_node(LINE, tPRIVATE, $1, *$2, $3); delete $2; }
       | tPUBLIC  tTYPE_AUTO tIDENTIFIER '=' expr        { $$ = new udf::variable_declaration_node(LINE, tPUBLIC,  nullptr, *$3, $5); delete $3; }
       |          tTYPE_AUTO tIDENTIFIER '=' expr        { $$ = new udf::variable_declaration_node(LINE, tPRIVATE, nullptr, *$2, $4); delete $2; }
       ;

vardecs : vardec ';'            { $$ = new cdk::sequence_node(LINE, $1);     }
        | vardecs vardec ';'    { $$ = new cdk::sequence_node(LINE, $2, $1); }
        ;

opt_vardecs  : /* empty */    { $$ = NULL; }
             | vardecs        { $$ = $1; }
             ;

opt_initializer  : /* empty */   { $$ = nullptr; /* must be nullptr, not NIL */ }
                 | '=' expr      { $$ = $2; }
                 ;

data_type : tTYPE_INT                        { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT); }
          | tTYPE_REAL                       { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
          | tTYPE_STRING                     { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
          | tTYPE_POINTER '<' data_type '>'  { $$ = cdk::reference_type::create(4, $3); }
          | tTYPE_POINTER '<' tTYPE_AUTO '>' { $$ = cdk::reference_type::create(4, nullptr); }
          | tTYPE_POINTER '<' void_type '>'  { $$ = cdk::reference_type::create(4, $3); }
          | tTYPE_TENSOR  '<' dims '>'       { $$ = cdk::tensor_type::create(*$3); delete $3; }
          ;

void_type : tTYPE_VOID                       { $$ = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
          ;

dim       : tINTEGER         { $$ = $1; }
          ;

dims      : dim             { $$ = new std::vector<size_t>({$1}); }
          | dims ',' dim    { $$ = $1; $$->push_back($3); }
          ;

fundec   :          data_type  tIDENTIFIER '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPRIVATE, $1, *$2, $4); delete $2; }
         | tFORWARD data_type  tIDENTIFIER '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPUBLIC,  $2, *$3, $5); delete $3; }
         | tPUBLIC  data_type  tIDENTIFIER '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPUBLIC,  $2, *$3, $5); delete $3; }
         |          tTYPE_AUTO tIDENTIFIER '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPRIVATE, nullptr, *$2, $4); delete $2; }
         | tFORWARD tTYPE_AUTO tIDENTIFIER '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPUBLIC,  nullptr, *$3, $5); delete $3; }
         | tPUBLIC  tTYPE_AUTO tIDENTIFIER '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPUBLIC,  nullptr, *$3, $5); delete $3; }
         |          void_type  tIDENTIFIER '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPRIVATE, $1, *$2, $4); delete $2; }
         | tFORWARD void_type  tIDENTIFIER '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPUBLIC,  $2, *$3, $5); delete $3; }
         | tPUBLIC  void_type  tIDENTIFIER '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPUBLIC,  $2, *$3, $5); delete $3; }
         ;

fundef   :          data_type  tIDENTIFIER '(' argdecs ')' block { $$ = new udf::function_definition_node(LINE, tPRIVATE, $1, *$2, $4, $6); delete $2; }
         | tPUBLIC  data_type  tIDENTIFIER '(' argdecs ')' block { $$ = new udf::function_definition_node(LINE, tPUBLIC,  $2, *$3, $5, $7); delete $3; }
         |          tTYPE_AUTO tIDENTIFIER '(' argdecs ')' block { $$ = new udf::function_definition_node(LINE, tPRIVATE, nullptr, *$2, $4, $6); delete $2; }
         | tPUBLIC  tTYPE_AUTO tIDENTIFIER '(' argdecs ')' block { $$ = new udf::function_definition_node(LINE, tPUBLIC,  nullptr, *$3, $5, $7); delete $3; }
         |          void_type  tIDENTIFIER '(' argdecs ')' block { $$ = new udf::function_definition_node(LINE, tPRIVATE, $1, *$2, $4, $6); delete $2; }
         | tPUBLIC  void_type  tIDENTIFIER '(' argdecs ')' block { $$ = new udf::function_definition_node(LINE, tPUBLIC,  $2, *$3, $5, $7); delete $3; }
         ;

argdecs  : /* empty */         { $$ = new cdk::sequence_node(LINE);  }
         |             argdec  { $$ = new cdk::sequence_node(LINE, $1);     }
         | argdecs ',' argdec  { $$ = new cdk::sequence_node(LINE, $3, $1); }
         ;

argdec   : data_type tIDENTIFIER { $$ = new udf::variable_declaration_node(LINE, tPRIVATE, $1, *$2, nullptr); delete $2; }
         ;

block    : '{' opt_vardecs opt_stmts '}' { $$ = new udf::block_node(LINE, $2, $3); }
         ;

fordec          : data_type tIDENTIFIER '=' expr { $$ = new udf::variable_declaration_node(LINE, tPRIVATE,  $1, *$2, $4); delete $2; }
                ;
              
fordecs         :             fordec { $$ = new cdk::sequence_node(LINE, $1);     }
                | fordecs ',' fordec { $$ = new cdk::sequence_node(LINE, $3, $1); }
                ;

opt_forinit     : /* empty */     { $$ = new cdk::sequence_node(LINE); }
                | fordecs         { $$ = $1; }
                | tTYPE_AUTO tIDENTIFIER '=' expr {
                  $$ = new cdk::sequence_node(LINE, new udf::variable_declaration_node(LINE, tPRIVATE, nullptr, *$2, $4));
                  delete $2;
                }
                | exprs { $$ = $1; }
                ;

return    : tRETURN      ';' { $$ = new udf::return_node(LINE, nullptr); }
          | tRETURN expr ';' { $$ = new udf::return_node(LINE, $2); }
          ;

stmts     : stmt       { $$ = new cdk::sequence_node(LINE, $1); }
          | stmts stmt { $$ = new cdk::sequence_node(LINE, $2, $1); }
          ;

opt_stmts : /* empty */  { $$ = new cdk::sequence_node(LINE); }
          | stmts        { $$ = $1; }
          ;

stmt      : expr ';'                                      { $$ = new udf::evaluation_node(LINE, $1); }
          | tWRITE exprs ';'                              { $$ = new udf::print_node(LINE, $2, false); }
          | tWRITELN exprs ';'                            { $$ = new udf::print_node(LINE, $2, true); }
          | tBREAK                                        { $$ = new udf::break_node(LINE); }
          | tCONTINUE                                     { $$ = new udf::continue_node(LINE); }
          | return                                        { $$ = $1; }
          | tIF '(' expr ')' stmt %prec tIFX              { $$ = new udf::if_node(LINE, $3, $5); }
          | tIF '(' expr ')' stmt iffalse                 { $$ = new udf::if_else_node(LINE, $3, $5, $6); }
          | tFOR '(' opt_forinit ';' opt_exprs ';' opt_exprs ')' stmt   { $$ = new udf::for_node(LINE, $3, $5, $7, $9); }
          | tUNLESS expr '?' expr ':' tIDENTIFIER expr ';'    { $$ = new udf::unless_node(LINE, $2, $4, *$6, $7); delete $6; }
          | block                                         { $$ = $1; }
          ;

iffalse   : tELSE stmt                            { $$ = $2; }
          | tELIF '(' expr ')' stmt %prec tELIFX  { $$ = new udf::if_node(LINE, $3, $5); }
          | tELIF '(' expr ')' stmt iffalse       { $$ = new udf::if_else_node(LINE, $3, $5, $6); }
          ;

expr      : integer                          { $$ = $1; }
          | real                             { $$ = $1; }
          | string                           { $$ = new cdk::string_node(LINE, $1); }
          | tNULLPTR                         { $$ = new udf::nullptr_node(LINE); }
          | '-' expr %prec tUNARY            { $$ = new cdk::unary_minus_node(LINE, $2); }
          | '+' expr %prec tUNARY            { $$ = new cdk::unary_plus_node(LINE, $2); }
          | '~' expr                         { $$ = new cdk::not_node(LINE, $2); }
          | expr '+' expr                    { $$ = new cdk::add_node(LINE, $1, $3); }
          | expr '-' expr                    { $$ = new cdk::sub_node(LINE, $1, $3); }
          | expr '*' expr                    { $$ = new cdk::mul_node(LINE, $1, $3); }
          | expr '/' expr                    { $$ = new cdk::div_node(LINE, $1, $3); }
          | expr '%' expr                    { $$ = new cdk::mod_node(LINE, $1, $3); }
          | expr '<' expr                    { $$ = new cdk::lt_node(LINE, $1, $3); }
          | expr '>' expr                    { $$ = new cdk::gt_node(LINE, $1, $3); }
          | expr tGE expr                    { $$ = new cdk::ge_node(LINE, $1, $3); }
          | expr tLE expr                    { $$ = new cdk::le_node(LINE, $1, $3); }
          | expr tNE expr                    { $$ = new cdk::ne_node(LINE, $1, $3); }
          | expr tEQ expr                    { $$ = new cdk::eq_node(LINE, $1, $3); }
          | expr tAND expr                   { $$ = new cdk::and_node(LINE, $1, $3); }
          | expr tOR  expr                   { $$ = new cdk::or_node (LINE, $1, $3); }
          | tINPUT                           { $$ = new udf::input_node(LINE); }
          | tSIZEOF  '(' expr ')'            { $$ = new udf::sizeof_node(LINE, $3); }
          | tOBJECTS '(' expr ')'            { $$ = new udf::stack_alloc_node(LINE, $3); }
          | '(' expr ')'                     { $$ = $2; }
          | lval                             { $$ = new cdk::rvalue_node(LINE, $1); }
          | lval '=' expr                    { $$ = new cdk::assignment_node(LINE, $1, $3); }
          | lval '?'                         { $$ = new udf::address_of_node(LINE, $1); }
          | tensor_expr                      { $$ = $1; }
          | expr '.' tCAPACITY               { $$ = new udf::tensor_capacity_node(LINE, $1); }
          | expr '.' tRANK                   { $$ = new udf::tensor_rank_node(LINE, $1); }
          | expr '.' tDIM '(' expr ')'       { $$ = new udf::tensor_dimension_node(LINE, $1, $5); }
          | expr '.' tDIMS                   { $$ = new udf::tensor_dimensions_node(LINE, $1); }
          | expr '.' tRESHAPE '(' exprs ')'  { $$ = new udf::tensor_reshape_node(LINE, $1, $5); }
          | expr tCONTRACTION expr           { $$ = new udf::tensor_contraction_node(LINE, $1, $3); }
          | tIDENTIFIER '(' opt_exprs ')'    { $$ = new udf::function_call_node(LINE, *$1, $3); delete $1; }
          ;

exprs     : expr               { $$ = new cdk::sequence_node(LINE, $1);     }
          | exprs ',' expr     { $$ = new cdk::sequence_node(LINE, $3, $1); }
          ;

opt_exprs : /* empty */   { $$ = new cdk::sequence_node(LINE); }
          | exprs         { $$ = $1; }
          ;

tensor_expr : '[' tensor_elems ']'             { $$ = new udf::tensor_node(LINE, $2); }
            ;

tensor_elems : tensor_elem                     { $$ = new cdk::sequence_node(LINE, $1); }
             | tensor_elems ',' tensor_elem    { $$ = new cdk::sequence_node(LINE, $3, $1); }
             ;

tensor_elem : expr             { $$ = $1; }
            ;

lval      : tIDENTIFIER                                { $$ = new cdk::variable_node(LINE, $1); }
          | expr '@' '(' exprs ')'                     { $$ = new udf::tensor_index_node(LINE, $1, $4); }
          | expr '[' expr ']'                          { $$ = new udf::index_node(LINE, $1, $3); }
          ;

integer   : tINTEGER                      { $$ = new cdk::integer_node(LINE, $1); }
real      : tREAL                         { $$ = new cdk::double_node(LINE, $1); }
string    : tSTRING                       { $$ = $1; }
          | string tSTRING                { $$ = $1; $$->append(*$2); delete $2; }
          ;

%%
