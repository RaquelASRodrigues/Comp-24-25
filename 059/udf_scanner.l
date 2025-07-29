%option c++ prefix="udf_scanner_" outfile="udf_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "udf_parser.tab.h"

// output stream for building string literals
static std::ostringstream strlit;

// don't change this
#define yyerror LexerError

#define PARSE_DOUBLE {                      \
  try {                                     \
    yylval.d = std::stod(yytext, NULL);     \
    return tREAL;                           \
  } catch (const std::out_of_range&) {      \
    yyerror("Real overflow.");              \
  }                                         \
}                                           \

%}

SPACE [ \t\r\n]

%x X_COMMENT
%x X_STRING X_SPECIAL X_NULL_TERMINATOR
%x X_HEX_INT

%%
  yydebug=1; set_debug(1);

  /* ====================================================================== */
  /* ====[                          COMMENTS                          ]==== */
  /* ====================================================================== */

"//".*$                ; /* ignore comments - match the whole line */

"/*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"/*"        yy_push_state(X_COMMENT);  /* nested comments */
<X_COMMENT>"*/"        yy_pop_state();
<X_COMMENT>.|\n        ; /* ignore content */

  /* ====================================================================== */
  /* ====[                       Tipos de dados                       ]==== */
  /* ====[                       Símbolos globais                     ]==== */
  /* ====================================================================== */

"auto"                 return tTYPE_AUTO;
"int"                  return tTYPE_INT;
"real"                 return tTYPE_REAL;
"string"               return tTYPE_STRING;
"tensor"               return tTYPE_TENSOR;
"void"                 return tTYPE_VOID;
"ptr"                  return tTYPE_POINTER;
[<>]                   return *yytext;

"public"               return tPUBLIC;
"forward"              return tFORWARD;

  /* ====================================================================== */
  /* ====[                    Instrução condicional                   ]==== */
  /* ====================================================================== */

"if"                   return tIF;
"elif"                 return tELIF;
"else"                 return tELSE;
"unless"               return tUNLESS;

  /* ====================================================================== */
  /* ====[                    Instrução de iteração                   ]==== */
  /* ====[                    Instrução de terminação                 ]==== */
  /* ====[                    Instrução de continuação                ]==== */
  /* ====[                    Instrução de retorno                    ]==== */
  /* ====================================================================== */

"for"                  return tFOR;
"break"                return tBREAK;
"continue"             return tCONTINUE;
"return"               return tRETURN;

  /* ====================================================================== */
  /* ====[                    Operadores de expressões                ]==== */
  /* ====[                    Expressões especiais                    ]==== */
  /* ====================================================================== */

[\[\]()]               return *yytext;
[-+*/%~<>@?=.:]        return *yytext;
">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE;
"&&"                   return tAND;
"||"                   return tOR;

"input"                return tINPUT;
"nullptr"              return tNULLPTR;
"sizeof"               return tSIZEOF;
"objects"              return tOBJECTS;

  /* ====================================================================== */
  /* ====[                    Delimitadores e separadores             ]==== */
  /* ====================================================================== */

[\[\](){},;]                return *yytext;

  /* ====================================================================== */
  /* ====[                    Expressões de tensores                  ]==== */
  /* ====================================================================== */

"capacity"             return tCAPACITY;
"rank"                 return tRANK;
"dim"                  return tDIM;
"dims"                 return tDIMS;
"reshape"              return tRESHAPE;
"**"                   return tCONTRACTION;

  /* ====================================================================== */
  /* ====[                    Instruções de impressão                 ]==== */
  /* ====================================================================== */

"write"                return tWRITE;
"writeln"              return tWRITELN;

  /* ====================================================================== */
  /* ====[                           inteiros                         ]==== */
  /* ====================================================================== */

[[:digit:]]+                  {
                                try {
                                  yylval.i = std::stoul(yytext, NULL, 10);
                                  return tINTEGER;
                                } catch (const std::out_of_range&) {
                                  yyerror("Integer overflow.");
                                }
                              }

"0x"                          yy_push_state(X_HEX_INT);

<X_HEX_INT>[[:xdigit:]]+      {
                                try {
                                  yylval.i = std::stoul(yytext, NULL, 16);
                                  yy_pop_state();
                                  return tINTEGER;
                                } catch (const std::out_of_range&) {
                                  yyerror("Hexadecimal integer overflow.");
                                }
                              }
<X_HEX_INT>.|\n               yyerror("Invalid base 16 number.");

  /* ====================================================================== */
  /* ====[                            reais                           ]==== */
  /* ====================================================================== */

([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)([eE][-+]?[0-9]+)?         PARSE_DOUBLE;
([0-9]+)([eE][-+]?[0-9]+)                                 PARSE_DOUBLE;

  /* ====================================================================== */
  /* ====[                   Identificadores (nomes)                  ]==== */
  /* ====================================================================== */

[A-Za-z][A-Za-z0-9_]*  yylval.s = new std::string(yytext); return tIDENTIFIER;

  /* ====================================================================== */
  /* ====[                    Cadeias de caracteres                   ]==== */
  /* ====================================================================== */

\"                    yy_push_state(X_STRING);
<X_STRING>\\          yy_push_state(X_SPECIAL);
<X_STRING>\"          {
                        yylval.s = new std::string(strlit.str());
                        strlit.str("");
                        yy_pop_state();
                        return tSTRING;
                      }
<X_STRING>.           strlit << *yytext;

<X_SPECIAL>n          strlit << '\n'; yy_pop_state();
<X_SPECIAL>r          strlit << '\r'; yy_pop_state();
<X_SPECIAL>t          strlit << '\t'; yy_pop_state();
<X_SPECIAL>"\""       strlit << '"';  yy_pop_state();
<X_SPECIAL>"\\"       strlit << '\\'; yy_pop_state();
<X_SPECIAL>0          yy_pop_state(); yy_push_state(X_NULL_TERMINATOR);

<X_SPECIAL>[[:xdigit:]]{1,2} {
                               strlit << (char)(unsigned char)strtoul(yytext, NULL, 16);
                               yy_pop_state();
                             }
<X_SPECIAL>.                 strlit << *yytext; yy_pop_state();

<X_NULL_TERMINATOR>\"       {
                              yylval.s = new std::string(strlit.str());
                              strlit.str("");
                              yy_pop_state();
                              yy_pop_state();
                              return tSTRING;
                            }
<X_NULL_TERMINATOR>\0       yyerror("null character in string");
<X_NULL_TERMINATOR>.        ;

  /* ====================================================================== */
  /* ====[                    (other characters)                      ]==== */
  /* ====================================================================== */

{SPACE}                /* ignore remaining white spaces inside the program */
.                      yyerror(yytext);    /* all other chars: error! */


%%
