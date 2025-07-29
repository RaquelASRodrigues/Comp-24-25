/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "udf_parser.y"

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

#line 85 "udf_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "udf_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tTYPE_INT = 3,                  /* tTYPE_INT  */
  YYSYMBOL_tTYPE_REAL = 4,                 /* tTYPE_REAL  */
  YYSYMBOL_tTYPE_STRING = 5,               /* tTYPE_STRING  */
  YYSYMBOL_tTYPE_POINTER = 6,              /* tTYPE_POINTER  */
  YYSYMBOL_tTYPE_AUTO = 7,                 /* tTYPE_AUTO  */
  YYSYMBOL_tTYPE_VOID = 8,                 /* tTYPE_VOID  */
  YYSYMBOL_tTYPE_TENSOR = 9,               /* tTYPE_TENSOR  */
  YYSYMBOL_tINTEGER = 10,                  /* tINTEGER  */
  YYSYMBOL_tREAL = 11,                     /* tREAL  */
  YYSYMBOL_tIDENTIFIER = 12,               /* tIDENTIFIER  */
  YYSYMBOL_tSTRING = 13,                   /* tSTRING  */
  YYSYMBOL_tNULLPTR = 14,                  /* tNULLPTR  */
  YYSYMBOL_tFOR = 15,                      /* tFOR  */
  YYSYMBOL_tIF = 16,                       /* tIF  */
  YYSYMBOL_tELIF = 17,                     /* tELIF  */
  YYSYMBOL_tELSE = 18,                     /* tELSE  */
  YYSYMBOL_tINPUT = 19,                    /* tINPUT  */
  YYSYMBOL_tWRITE = 20,                    /* tWRITE  */
  YYSYMBOL_tWRITELN = 21,                  /* tWRITELN  */
  YYSYMBOL_tSIZEOF = 22,                   /* tSIZEOF  */
  YYSYMBOL_tOBJECTS = 23,                  /* tOBJECTS  */
  YYSYMBOL_tUNLESS = 24,                   /* tUNLESS  */
  YYSYMBOL_tAND = 25,                      /* tAND  */
  YYSYMBOL_tOR = 26,                       /* tOR  */
  YYSYMBOL_tPUBLIC = 27,                   /* tPUBLIC  */
  YYSYMBOL_tPRIVATE = 28,                  /* tPRIVATE  */
  YYSYMBOL_tFORWARD = 29,                  /* tFORWARD  */
  YYSYMBOL_tBREAK = 30,                    /* tBREAK  */
  YYSYMBOL_tCONTINUE = 31,                 /* tCONTINUE  */
  YYSYMBOL_tRETURN = 32,                   /* tRETURN  */
  YYSYMBOL_tCAPACITY = 33,                 /* tCAPACITY  */
  YYSYMBOL_tRANK = 34,                     /* tRANK  */
  YYSYMBOL_tDIM = 35,                      /* tDIM  */
  YYSYMBOL_tDIMS = 36,                     /* tDIMS  */
  YYSYMBOL_tRESHAPE = 37,                  /* tRESHAPE  */
  YYSYMBOL_tCONTRACTION = 38,              /* tCONTRACTION  */
  YYSYMBOL_tIFX = 39,                      /* tIFX  */
  YYSYMBOL_tELIFX = 40,                    /* tELIFX  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_42_ = 42,                       /* '~'  */
  YYSYMBOL_tEQ = 43,                       /* tEQ  */
  YYSYMBOL_tNE = 44,                       /* tNE  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_tLE = 46,                       /* tLE  */
  YYSYMBOL_tGE = 47,                       /* tGE  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* '+'  */
  YYSYMBOL_50_ = 50,                       /* '-'  */
  YYSYMBOL_51_ = 51,                       /* '*'  */
  YYSYMBOL_52_ = 52,                       /* '/'  */
  YYSYMBOL_53_ = 53,                       /* '%'  */
  YYSYMBOL_tUNARY = 54,                    /* tUNARY  */
  YYSYMBOL_55_ = 55,                       /* '.'  */
  YYSYMBOL_56_ = 56,                       /* '@'  */
  YYSYMBOL_57_ = 57,                       /* '('  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_59_ = 59,                       /* ';'  */
  YYSYMBOL_60_ = 60,                       /* ','  */
  YYSYMBOL_61_ = 61,                       /* ')'  */
  YYSYMBOL_62_ = 62,                       /* '{'  */
  YYSYMBOL_63_ = 63,                       /* '}'  */
  YYSYMBOL_64_ = 64,                       /* '?'  */
  YYSYMBOL_65_ = 65,                       /* ':'  */
  YYSYMBOL_66_ = 66,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_file = 68,                      /* file  */
  YYSYMBOL_declarations = 69,              /* declarations  */
  YYSYMBOL_declaration = 70,               /* declaration  */
  YYSYMBOL_vardec = 71,                    /* vardec  */
  YYSYMBOL_vardecs = 72,                   /* vardecs  */
  YYSYMBOL_opt_vardecs = 73,               /* opt_vardecs  */
  YYSYMBOL_opt_initializer = 74,           /* opt_initializer  */
  YYSYMBOL_data_type = 75,                 /* data_type  */
  YYSYMBOL_void_type = 76,                 /* void_type  */
  YYSYMBOL_dim = 77,                       /* dim  */
  YYSYMBOL_dims = 78,                      /* dims  */
  YYSYMBOL_fundec = 79,                    /* fundec  */
  YYSYMBOL_fundef = 80,                    /* fundef  */
  YYSYMBOL_argdecs = 81,                   /* argdecs  */
  YYSYMBOL_argdec = 82,                    /* argdec  */
  YYSYMBOL_block = 83,                     /* block  */
  YYSYMBOL_fordec = 84,                    /* fordec  */
  YYSYMBOL_fordecs = 85,                   /* fordecs  */
  YYSYMBOL_opt_forinit = 86,               /* opt_forinit  */
  YYSYMBOL_return = 87,                    /* return  */
  YYSYMBOL_stmts = 88,                     /* stmts  */
  YYSYMBOL_opt_stmts = 89,                 /* opt_stmts  */
  YYSYMBOL_stmt = 90,                      /* stmt  */
  YYSYMBOL_iffalse = 91,                   /* iffalse  */
  YYSYMBOL_expr = 92,                      /* expr  */
  YYSYMBOL_exprs = 93,                     /* exprs  */
  YYSYMBOL_opt_exprs = 94,                 /* opt_exprs  */
  YYSYMBOL_tensor_expr = 95,               /* tensor_expr  */
  YYSYMBOL_tensor_elems = 96,              /* tensor_elems  */
  YYSYMBOL_tensor_elem = 97,               /* tensor_elem  */
  YYSYMBOL_lval = 98,                      /* lval  */
  YYSYMBOL_integer = 99,                   /* integer  */
  YYSYMBOL_real = 100,                     /* real  */
  YYSYMBOL_string = 101                    /* string  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 84 "udf_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 224 "udf_parser.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   760

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  273

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    53,     2,     2,
      57,    61,    51,    49,    60,    50,    55,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,    59,
      45,    41,    48,    64,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    63,    42,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    43,    44,    46,    47,
      54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    92,    93,    96,    97,    98,   101,   102,
     103,   104,   105,   108,   109,   112,   113,   116,   117,   120,
     121,   122,   123,   124,   125,   126,   129,   132,   135,   136,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   150,
     151,   152,   153,   154,   155,   158,   159,   160,   163,   166,
     169,   172,   173,   176,   177,   178,   182,   185,   186,   189,
     190,   193,   194,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   210,   211,   212,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   252,   253,   256,   257,   260,   263,   264,   267,
     270,   271,   272,   275,   276,   277,   278
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tTYPE_INT",
  "tTYPE_REAL", "tTYPE_STRING", "tTYPE_POINTER", "tTYPE_AUTO",
  "tTYPE_VOID", "tTYPE_TENSOR", "tINTEGER", "tREAL", "tIDENTIFIER",
  "tSTRING", "tNULLPTR", "tFOR", "tIF", "tELIF", "tELSE", "tINPUT",
  "tWRITE", "tWRITELN", "tSIZEOF", "tOBJECTS", "tUNLESS", "tAND", "tOR",
  "tPUBLIC", "tPRIVATE", "tFORWARD", "tBREAK", "tCONTINUE", "tRETURN",
  "tCAPACITY", "tRANK", "tDIM", "tDIMS", "tRESHAPE", "tCONTRACTION",
  "tIFX", "tELIFX", "'='", "'~'", "tEQ", "tNE", "'<'", "tLE", "tGE", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "tUNARY", "'.'", "'@'", "'('", "'['",
  "';'", "','", "')'", "'{'", "'}'", "'?'", "':'", "']'", "$accept",
  "file", "declarations", "declaration", "vardec", "vardecs",
  "opt_vardecs", "opt_initializer", "data_type", "void_type", "dim",
  "dims", "fundec", "fundef", "argdecs", "argdec", "block", "fordec",
  "fordecs", "opt_forinit", "return", "stmts", "opt_stmts", "stmt",
  "iffalse", "expr", "exprs", "opt_exprs", "tensor_expr", "tensor_elems",
  "tensor_elem", "lval", "integer", "real", "string", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-241)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,  -241,  -241,  -241,   -40,    -5,  -241,   -30,   378,   409,
      42,    17,  -241,    20,    51,    83,  -241,  -241,   443,   -22,
      96,    87,   105,   115,   118,   128,   133,  -241,  -241,  -241,
      -4,   113,   125,   130,   136,   153,   109,  -241,  -241,   -44,
      -3,     4,   124,   131,   155,   157,   153,   109,  -241,   109,
    -241,  -241,  -241,  -241,  -241,   171,  -241,  -241,  -241,   173,
     187,   153,   153,   153,   153,   153,   659,  -241,   -31,  -241,
    -241,   185,   145,   -20,  -241,  -241,    96,   153,   109,   109,
    -241,   109,   109,   109,   109,   659,    44,    74,   153,   153,
     153,   659,    86,    86,   350,   659,    34,  -241,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,    89,   195,   153,   153,  -241,  -241,  -241,   109,
      91,  -241,   659,    88,    90,    98,   100,   108,   126,    91,
      91,   659,   193,   194,   384,   418,  -241,   153,  -241,   573,
     675,    86,   141,   141,   141,   141,   141,   141,   168,   168,
      -6,    -6,    -6,  -241,  -241,   197,  -241,   199,   153,   248,
     659,  -241,   731,  -241,    91,    91,    91,  -241,  -241,  -241,
    -241,  -241,   153,  -241,  -241,  -241,  -241,   153,   153,   140,
    -241,   249,   306,   109,   201,   731,   227,   252,  -241,  -241,
    -241,   659,   452,   144,  -241,   229,   259,   260,   263,  -241,
     219,   222,   223,   153,   153,   153,  -241,  -241,    97,  -241,
    -241,   227,   218,  -241,   554,   241,  -241,  -241,   242,   241,
    -241,  -241,    79,   153,   149,   158,   316,  -241,   589,  -241,
    -241,  -241,   275,   276,  -241,   230,   243,   193,   486,  -241,
    -241,   153,  -241,   264,   277,   109,   153,   227,   282,   153,
     153,  -241,   257,   217,   305,   659,   659,   153,   262,   227,
    -241,   153,   261,   153,  -241,   624,   227,   520,  -241,  -241,
     227,   217,  -241
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    19,    20,    21,     0,     0,    26,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     4,     5,
      17,     0,     0,     0,     0,     0,    45,    27,    28,     0,
       0,    17,     0,     0,     8,     0,     0,    45,    10,    45,
      23,    22,    24,   123,   124,   120,   125,    80,    97,     0,
       0,     0,     0,     0,     0,     0,    12,   104,   101,    77,
      78,    79,     0,     0,    46,    25,     0,     0,    45,    45,
       9,    45,    45,    45,    45,    18,     0,     0,   114,     0,
       0,    83,    82,    81,     0,   119,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   126,    48,     0,
      33,    29,    11,     0,     0,     0,     0,     0,     0,    30,
      36,   112,   115,     0,     0,     0,   100,     0,   116,    95,
      96,   110,    94,    93,    89,    92,    91,    90,    84,    85,
      86,    87,    88,   105,   106,     0,   108,     0,     0,     0,
     102,    47,    15,    41,    35,    32,    38,    34,    31,    37,
      39,    43,     0,   111,    98,    99,   118,     0,     0,     0,
     122,     0,     0,     0,     0,    16,    61,     0,    42,    40,
      44,   113,     0,     0,   121,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,     0,    66,    67,     0,    73,
      68,    62,     0,    59,     0,    17,   107,   109,     0,    17,
       8,    14,    53,     0,     0,     0,     0,    57,     0,    60,
      49,    63,     0,     0,    51,    54,     0,    56,     0,    64,
      65,     0,    58,     0,     0,     0,   114,     0,     0,     0,
       0,    52,     0,    69,     0,    55,    50,   114,     0,     0,
      70,     0,     0,     0,    74,     0,     0,     0,    72,    71,
       0,    75,    76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -241,  -241,  -241,   310,  -149,  -241,  -241,   -39,     0,    39,
     247,  -241,  -241,  -241,   184,   205,   -33,    94,  -241,  -241,
    -241,  -241,  -241,  -208,    65,   -34,  -144,  -240,  -241,  -241,
     206,  -241,  -241,  -241,  -241
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    10,    11,    12,    13,   185,   186,    48,    72,    15,
      38,    39,    16,    17,    73,    74,   209,   234,   235,   236,
     210,   211,   212,   213,   260,   131,   132,   133,    67,    96,
      97,    68,    69,    70,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    66,    80,   229,    75,    18,   252,    19,    22,    25,
     115,    14,    85,   184,   179,    20,    76,   262,    33,    35,
       1,     2,     3,     4,     5,     6,     7,    91,    92,    93,
      94,    95,   100,   116,   193,    36,   200,    46,    77,   253,
     119,   120,    27,   122,     8,    46,     9,    23,    26,   112,
     113,   264,   114,    47,    78,   134,   135,    34,   269,   224,
     225,    79,   271,    30,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   237,    29,
     159,   160,     1,     2,     3,     4,   232,   163,     7,    53,
      54,    55,    56,    57,   137,    31,   170,   171,    58,    40,
     138,    59,    60,    95,   119,   129,    37,    53,    54,    55,
      56,    57,     1,     2,     3,     4,    58,    41,     7,    59,
      60,    61,   153,   154,   155,   156,   157,    42,    62,    63,
      43,   188,   189,   190,   119,   130,    64,    65,   191,    61,
      44,   112,   113,   192,   114,    45,    62,    63,   119,   164,
     119,   165,   214,   162,    64,    65,   227,   118,   119,   166,
     119,   167,   187,    53,    54,    55,    56,    57,   119,   168,
      49,   226,    58,    50,   228,    59,    60,   214,    51,   100,
      80,    81,   197,   198,    52,   187,   119,   169,    82,   238,
     107,   108,   109,   110,   111,    61,   112,   113,   117,   114,
     172,   194,    62,    63,   172,   217,   100,   248,   239,   172,
      64,    65,    83,   214,    84,   255,   256,   240,   172,   109,
     110,   111,   233,   112,   113,   214,   114,   265,    88,   267,
      89,    86,   214,    87,   258,   259,   214,    53,    54,    55,
      56,    57,   201,   202,    90,   233,    58,   203,   204,    59,
      60,   205,   158,   172,   177,   173,   178,   206,   207,   208,
     199,   195,   123,   124,   215,   125,   126,   127,   128,    61,
      35,   218,   219,    98,    99,   220,    62,    63,   221,   222,
     223,   230,    46,    77,    64,    65,   100,   243,   244,   162,
     245,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   246,   112,   113,   249,   114,    98,    99,     1,
       2,     3,     4,   196,   180,     7,   257,   261,   250,   263,
     100,    28,   266,   121,   161,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   272,   112,   113,   251,
     114,    98,    99,   176,     0,     0,     0,   254,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,   112,   113,     0,   114,    98,    99,     0,     0,     0,
     241,     1,     2,     3,     4,    21,     6,     7,   100,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,   112,   113,     0,   114,    98,
      99,   136,     1,     2,     3,     4,    24,     6,     7,     0,
       0,     0,   100,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
     113,     0,   114,    98,    99,   174,     1,     2,     3,     4,
      32,     6,     7,     0,     0,     0,   100,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,   112,   113,     0,   114,    98,    99,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,   112,   113,     0,
     114,    98,    99,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,   112,   113,     0,   114,    98,    99,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,   112,   113,     0,   114,    98,
      99,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
     113,   100,   114,   231,    98,    99,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   100,   112,   113,
       0,   114,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     0,   112,   113,     0,   114,   242,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
     113,     0,   114,   268,    98,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,     0,     0,
      98,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   100,   112,   113,     0,   114,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
     112,   113,     0,   114,     1,     2,     3,     4,   181,     0,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,     0,
     183
};

static const yytype_int16 yycheck[] =
{
       0,    35,    41,   211,    48,    45,   246,    12,     8,     9,
      41,    11,    46,   162,   158,    45,    60,   257,    18,    41,
       3,     4,     5,     6,     7,     8,     9,    61,    62,    63,
      64,    65,    38,    64,   178,    57,   185,    41,    41,   247,
      60,    61,     0,    77,    27,    41,    29,     8,     9,    55,
      56,   259,    58,    57,    57,    89,    90,    18,   266,   203,
     204,    57,   270,    12,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   222,    59,
     114,   115,     3,     4,     5,     6,     7,   120,     9,    10,
      11,    12,    13,    14,    60,    12,   129,   130,    19,    12,
      66,    22,    23,   137,    60,    61,    10,    10,    11,    12,
      13,    14,     3,     4,     5,     6,    19,    12,     9,    22,
      23,    42,    33,    34,    35,    36,    37,    12,    49,    50,
      12,   164,   165,   166,    60,    61,    57,    58,   172,    42,
      12,    55,    56,   177,    58,    12,    49,    50,    60,    61,
      60,    61,   186,    62,    57,    58,    59,    12,    60,    61,
      60,    61,   162,    10,    11,    12,    13,    14,    60,    61,
      57,   205,    19,    48,   208,    22,    23,   211,    48,    38,
     219,    57,   182,   183,    48,   185,    60,    61,    57,   223,
      49,    50,    51,    52,    53,    42,    55,    56,    13,    58,
      60,    61,    49,    50,    60,    61,    38,   241,    59,    60,
      57,    58,    57,   247,    57,   249,   250,    59,    60,    51,
      52,    53,   222,    55,    56,   259,    58,   261,    57,   263,
      57,    47,   266,    49,    17,    18,   270,    10,    11,    12,
      13,    14,    15,    16,    57,   245,    19,    20,    21,    22,
      23,    24,    57,    60,    57,    61,    57,    30,    31,    32,
      59,    12,    78,    79,    12,    81,    82,    83,    84,    42,
      41,    12,    12,    25,    26,    12,    49,    50,    59,    57,
      57,    63,    41,    41,    57,    58,    38,    12,    12,    62,
      60,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    59,    55,    56,    41,    58,    25,    26,     3,
       4,     5,     6,     7,    66,     9,    59,    12,    41,    57,
      38,    11,    61,    76,   119,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,   271,    55,    56,   245,
      58,    25,    26,   137,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    25,    26,    -1,    -1,    -1,
      64,     3,     4,     5,     6,     7,     8,     9,    38,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    25,
      26,    61,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    25,    26,    61,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    58,    25,    26,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      58,    25,    26,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    25,    26,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    25,
      26,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    38,    58,    59,    25,    26,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    38,    55,    56,
      -1,    58,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    58,    59,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    59,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      25,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    38,    55,    56,    -1,    58,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    -1,    58,     3,     4,     5,     6,     7,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    27,    29,
      68,    69,    70,    71,    75,    76,    79,    80,    45,    12,
      45,     7,    75,    76,     7,    75,    76,     0,    70,    59,
      12,    12,     7,    75,    76,    41,    57,    10,    77,    78,
      12,    12,    12,    12,    12,    12,    41,    57,    74,    57,
      48,    48,    48,    10,    11,    12,    13,    14,    19,    22,
      23,    42,    49,    50,    57,    58,    92,    95,    98,    99,
     100,   101,    75,    81,    82,    48,    60,    41,    57,    57,
      74,    57,    57,    57,    57,    92,    81,    81,    57,    57,
      57,    92,    92,    92,    92,    92,    96,    97,    25,    26,
      38,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    55,    56,    58,    41,    64,    13,    12,    60,
      61,    77,    92,    81,    81,    81,    81,    81,    81,    61,
      61,    92,    93,    94,    92,    92,    61,    60,    66,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    33,    34,    35,    36,    37,    57,    92,
      92,    82,    62,    83,    61,    61,    61,    61,    61,    61,
      83,    83,    60,    61,    61,    61,    97,    57,    57,    93,
      66,     7,    27,    29,    71,    72,    73,    75,    83,    83,
      83,    92,    92,    93,    61,    12,     7,    75,    75,    59,
      71,    15,    16,    20,    21,    24,    30,    31,    32,    83,
      87,    88,    89,    90,    92,    12,    61,    61,    12,    12,
      12,    59,    57,    57,    93,    93,    92,    59,    92,    90,
      63,    59,     7,    75,    84,    85,    86,    93,    92,    59,
      59,    64,    59,    12,    12,    60,    59,    61,    92,    41,
      41,    84,    94,    90,    65,    92,    92,    59,    17,    18,
      91,    12,    94,    57,    90,    92,    61,    92,    59,    90,
      61,    90,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    69,    69,    70,    70,    70,    71,    71,
      71,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    76,    77,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    81,    81,    81,    82,    83,
      84,    85,    85,    86,    86,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    94,    94,    95,    96,    96,    97,
      98,    98,    98,    99,   100,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     3,     4,
       3,     5,     4,     2,     3,     0,     1,     0,     2,     1,
       1,     1,     4,     4,     4,     4,     1,     1,     1,     3,
       5,     6,     6,     5,     6,     6,     5,     6,     6,     6,
       7,     6,     7,     6,     7,     0,     1,     3,     2,     4,
       4,     1,     3,     0,     1,     4,     1,     2,     3,     1,
       2,     0,     1,     2,     3,     3,     1,     1,     1,     5,
       6,     9,     8,     1,     2,     5,     6,     1,     1,     1,
       1,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     4,
       3,     1,     3,     2,     1,     3,     3,     6,     3,     6,
       3,     4,     1,     3,     0,     1,     3,     1,     3,     1,
       1,     5,     4,     1,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (compiler, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (compiler);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, compiler);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, std::shared_ptr<cdk::compiler> compiler)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YY_USE (yyvaluep);
  YY_USE (compiler);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::shared_ptr<cdk::compiler> compiler)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* file: declarations  */
#line 89 "udf_parser.y"
                            { compiler->ast((yyval.sequence) = (yyvsp[0].sequence)); }
#line 1461 "udf_parser.tab.c"
    break;

  case 3: /* declarations: declaration  */
#line 92 "udf_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1467 "udf_parser.tab.c"
    break;

  case 4: /* declarations: declarations declaration  */
#line 93 "udf_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1473 "udf_parser.tab.c"
    break;

  case 5: /* declaration: vardec ';'  */
#line 96 "udf_parser.y"
                          { (yyval.node) = (yyvsp[-1].node); }
#line 1479 "udf_parser.tab.c"
    break;

  case 6: /* declaration: fundec  */
#line 97 "udf_parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1485 "udf_parser.tab.c"
    break;

  case 7: /* declaration: fundef  */
#line 98 "udf_parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1491 "udf_parser.tab.c"
    break;

  case 8: /* vardec: tFORWARD data_type tIDENTIFIER  */
#line 101 "udf_parser.y"
                                                         { (yyval.node) = new udf::variable_declaration_node(LINE, tPUBLIC,  (yyvsp[-1].type), *(yyvsp[0].s), nullptr); delete (yyvsp[0].s); }
#line 1497 "udf_parser.tab.c"
    break;

  case 9: /* vardec: tPUBLIC data_type tIDENTIFIER opt_initializer  */
#line 102 "udf_parser.y"
                                                         { (yyval.node) = new udf::variable_declaration_node(LINE, tPUBLIC,  (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); delete (yyvsp[-1].s); }
#line 1503 "udf_parser.tab.c"
    break;

  case 10: /* vardec: data_type tIDENTIFIER opt_initializer  */
#line 103 "udf_parser.y"
                                                         { (yyval.node) = new udf::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); delete (yyvsp[-1].s); }
#line 1509 "udf_parser.tab.c"
    break;

  case 11: /* vardec: tPUBLIC tTYPE_AUTO tIDENTIFIER '=' expr  */
#line 104 "udf_parser.y"
                                                         { (yyval.node) = new udf::variable_declaration_node(LINE, tPUBLIC,  nullptr, *(yyvsp[-2].s), (yyvsp[0].expression)); delete (yyvsp[-2].s); }
#line 1515 "udf_parser.tab.c"
    break;

  case 12: /* vardec: tTYPE_AUTO tIDENTIFIER '=' expr  */
#line 105 "udf_parser.y"
                                                         { (yyval.node) = new udf::variable_declaration_node(LINE, tPRIVATE, nullptr, *(yyvsp[-2].s), (yyvsp[0].expression)); delete (yyvsp[-2].s); }
#line 1521 "udf_parser.tab.c"
    break;

  case 13: /* vardecs: vardec ';'  */
#line 108 "udf_parser.y"
                                { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node));     }
#line 1527 "udf_parser.tab.c"
    break;

  case 14: /* vardecs: vardecs vardec ';'  */
#line 109 "udf_parser.y"
                                { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1533 "udf_parser.tab.c"
    break;

  case 15: /* opt_vardecs: %empty  */
#line 112 "udf_parser.y"
                              { (yyval.sequence) = NULL; }
#line 1539 "udf_parser.tab.c"
    break;

  case 16: /* opt_vardecs: vardecs  */
#line 113 "udf_parser.y"
                              { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1545 "udf_parser.tab.c"
    break;

  case 17: /* opt_initializer: %empty  */
#line 116 "udf_parser.y"
                                 { (yyval.expression) = nullptr; /* must be nullptr, not NIL */ }
#line 1551 "udf_parser.tab.c"
    break;

  case 18: /* opt_initializer: '=' expr  */
#line 117 "udf_parser.y"
                                 { (yyval.expression) = (yyvsp[0].expression); }
#line 1557 "udf_parser.tab.c"
    break;

  case 19: /* data_type: tTYPE_INT  */
#line 120 "udf_parser.y"
                                             { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT); }
#line 1563 "udf_parser.tab.c"
    break;

  case 20: /* data_type: tTYPE_REAL  */
#line 121 "udf_parser.y"
                                             { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
#line 1569 "udf_parser.tab.c"
    break;

  case 21: /* data_type: tTYPE_STRING  */
#line 122 "udf_parser.y"
                                             { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
#line 1575 "udf_parser.tab.c"
    break;

  case 22: /* data_type: tTYPE_POINTER '<' data_type '>'  */
#line 123 "udf_parser.y"
                                             { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1581 "udf_parser.tab.c"
    break;

  case 23: /* data_type: tTYPE_POINTER '<' tTYPE_AUTO '>'  */
#line 124 "udf_parser.y"
                                             { (yyval.type) = cdk::reference_type::create(4, nullptr); }
#line 1587 "udf_parser.tab.c"
    break;

  case 24: /* data_type: tTYPE_POINTER '<' void_type '>'  */
#line 125 "udf_parser.y"
                                             { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1593 "udf_parser.tab.c"
    break;

  case 25: /* data_type: tTYPE_TENSOR '<' dims '>'  */
#line 126 "udf_parser.y"
                                             { (yyval.type) = cdk::tensor_type::create(*(yyvsp[-1].dims)); delete (yyvsp[-1].dims); }
#line 1599 "udf_parser.tab.c"
    break;

  case 26: /* void_type: tTYPE_VOID  */
#line 129 "udf_parser.y"
                                             { (yyval.type) = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
#line 1605 "udf_parser.tab.c"
    break;

  case 27: /* dim: tINTEGER  */
#line 132 "udf_parser.y"
                             { (yyval.sz) = (yyvsp[0].i); }
#line 1611 "udf_parser.tab.c"
    break;

  case 28: /* dims: dim  */
#line 135 "udf_parser.y"
                            { (yyval.dims) = new std::vector<size_t>({(yyvsp[0].sz)}); }
#line 1617 "udf_parser.tab.c"
    break;

  case 29: /* dims: dims ',' dim  */
#line 136 "udf_parser.y"
                            { (yyval.dims) = (yyvsp[-2].dims); (yyval.dims)->push_back((yyvsp[0].sz)); }
#line 1623 "udf_parser.tab.c"
    break;

  case 30: /* fundec: data_type tIDENTIFIER '(' argdecs ')'  */
#line 139 "udf_parser.y"
                                                           { (yyval.node) = new udf::function_declaration_node(LINE, tPRIVATE, (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1629 "udf_parser.tab.c"
    break;

  case 31: /* fundec: tFORWARD data_type tIDENTIFIER '(' argdecs ')'  */
#line 140 "udf_parser.y"
                                                           { (yyval.node) = new udf::function_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1635 "udf_parser.tab.c"
    break;

  case 32: /* fundec: tPUBLIC data_type tIDENTIFIER '(' argdecs ')'  */
#line 141 "udf_parser.y"
                                                           { (yyval.node) = new udf::function_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1641 "udf_parser.tab.c"
    break;

  case 33: /* fundec: tTYPE_AUTO tIDENTIFIER '(' argdecs ')'  */
#line 142 "udf_parser.y"
                                                           { (yyval.node) = new udf::function_declaration_node(LINE, tPRIVATE, nullptr, *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1647 "udf_parser.tab.c"
    break;

  case 34: /* fundec: tFORWARD tTYPE_AUTO tIDENTIFIER '(' argdecs ')'  */
#line 143 "udf_parser.y"
                                                           { (yyval.node) = new udf::function_declaration_node(LINE, tPUBLIC,  nullptr, *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1653 "udf_parser.tab.c"
    break;

  case 35: /* fundec: tPUBLIC tTYPE_AUTO tIDENTIFIER '(' argdecs ')'  */
#line 144 "udf_parser.y"
                                                           { (yyval.node) = new udf::function_declaration_node(LINE, tPUBLIC,  nullptr, *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1659 "udf_parser.tab.c"
    break;

  case 36: /* fundec: void_type tIDENTIFIER '(' argdecs ')'  */
#line 145 "udf_parser.y"
                                                           { (yyval.node) = new udf::function_declaration_node(LINE, tPRIVATE, (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1665 "udf_parser.tab.c"
    break;

  case 37: /* fundec: tFORWARD void_type tIDENTIFIER '(' argdecs ')'  */
#line 146 "udf_parser.y"
                                                           { (yyval.node) = new udf::function_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1671 "udf_parser.tab.c"
    break;

  case 38: /* fundec: tPUBLIC void_type tIDENTIFIER '(' argdecs ')'  */
#line 147 "udf_parser.y"
                                                           { (yyval.node) = new udf::function_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1677 "udf_parser.tab.c"
    break;

  case 39: /* fundef: data_type tIDENTIFIER '(' argdecs ')' block  */
#line 150 "udf_parser.y"
                                                                 { (yyval.node) = new udf::function_definition_node(LINE, tPRIVATE, (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); delete (yyvsp[-4].s); }
#line 1683 "udf_parser.tab.c"
    break;

  case 40: /* fundef: tPUBLIC data_type tIDENTIFIER '(' argdecs ')' block  */
#line 151 "udf_parser.y"
                                                                 { (yyval.node) = new udf::function_definition_node(LINE, tPUBLIC,  (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); delete (yyvsp[-4].s); }
#line 1689 "udf_parser.tab.c"
    break;

  case 41: /* fundef: tTYPE_AUTO tIDENTIFIER '(' argdecs ')' block  */
#line 152 "udf_parser.y"
                                                                 { (yyval.node) = new udf::function_definition_node(LINE, tPRIVATE, nullptr, *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); delete (yyvsp[-4].s); }
#line 1695 "udf_parser.tab.c"
    break;

  case 42: /* fundef: tPUBLIC tTYPE_AUTO tIDENTIFIER '(' argdecs ')' block  */
#line 153 "udf_parser.y"
                                                                 { (yyval.node) = new udf::function_definition_node(LINE, tPUBLIC,  nullptr, *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); delete (yyvsp[-4].s); }
#line 1701 "udf_parser.tab.c"
    break;

  case 43: /* fundef: void_type tIDENTIFIER '(' argdecs ')' block  */
#line 154 "udf_parser.y"
                                                                 { (yyval.node) = new udf::function_definition_node(LINE, tPRIVATE, (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); delete (yyvsp[-4].s); }
#line 1707 "udf_parser.tab.c"
    break;

  case 44: /* fundef: tPUBLIC void_type tIDENTIFIER '(' argdecs ')' block  */
#line 155 "udf_parser.y"
                                                                 { (yyval.node) = new udf::function_definition_node(LINE, tPUBLIC,  (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); delete (yyvsp[-4].s); }
#line 1713 "udf_parser.tab.c"
    break;

  case 45: /* argdecs: %empty  */
#line 158 "udf_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE);  }
#line 1719 "udf_parser.tab.c"
    break;

  case 46: /* argdecs: argdec  */
#line 159 "udf_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1725 "udf_parser.tab.c"
    break;

  case 47: /* argdecs: argdecs ',' argdec  */
#line 160 "udf_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1731 "udf_parser.tab.c"
    break;

  case 48: /* argdec: data_type tIDENTIFIER  */
#line 163 "udf_parser.y"
                                 { (yyval.node) = new udf::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); delete (yyvsp[0].s); }
#line 1737 "udf_parser.tab.c"
    break;

  case 49: /* block: '{' opt_vardecs opt_stmts '}'  */
#line 166 "udf_parser.y"
                                         { (yyval.block) = new udf::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1743 "udf_parser.tab.c"
    break;

  case 50: /* fordec: data_type tIDENTIFIER '=' expr  */
#line 169 "udf_parser.y"
                                                 { (yyval.node) = new udf::variable_declaration_node(LINE, tPRIVATE,  (yyvsp[-3].type), *(yyvsp[-2].s), (yyvsp[0].expression)); delete (yyvsp[-2].s); }
#line 1749 "udf_parser.tab.c"
    break;

  case 51: /* fordecs: fordec  */
#line 172 "udf_parser.y"
                                     { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1755 "udf_parser.tab.c"
    break;

  case 52: /* fordecs: fordecs ',' fordec  */
#line 173 "udf_parser.y"
                                     { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1761 "udf_parser.tab.c"
    break;

  case 53: /* opt_forinit: %empty  */
#line 176 "udf_parser.y"
                                  { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1767 "udf_parser.tab.c"
    break;

  case 54: /* opt_forinit: fordecs  */
#line 177 "udf_parser.y"
                                  { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1773 "udf_parser.tab.c"
    break;

  case 55: /* opt_forinit: tTYPE_AUTO tIDENTIFIER '=' expr  */
#line 178 "udf_parser.y"
                                                  {
                  (yyval.sequence) = new cdk::sequence_node(LINE, new udf::variable_declaration_node(LINE, tPRIVATE, nullptr, *(yyvsp[-2].s), (yyvsp[0].expression)));
                  delete (yyvsp[-2].s);
                }
#line 1782 "udf_parser.tab.c"
    break;

  case 56: /* opt_forinit: exprs  */
#line 182 "udf_parser.y"
                        { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1788 "udf_parser.tab.c"
    break;

  case 57: /* return: tRETURN ';'  */
#line 185 "udf_parser.y"
                             { (yyval.node) = new udf::return_node(LINE, nullptr); }
#line 1794 "udf_parser.tab.c"
    break;

  case 58: /* return: tRETURN expr ';'  */
#line 186 "udf_parser.y"
                             { (yyval.node) = new udf::return_node(LINE, (yyvsp[-1].expression)); }
#line 1800 "udf_parser.tab.c"
    break;

  case 59: /* stmts: stmt  */
#line 189 "udf_parser.y"
                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1806 "udf_parser.tab.c"
    break;

  case 60: /* stmts: stmts stmt  */
#line 190 "udf_parser.y"
                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1812 "udf_parser.tab.c"
    break;

  case 61: /* opt_stmts: %empty  */
#line 193 "udf_parser.y"
                         { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1818 "udf_parser.tab.c"
    break;

  case 62: /* opt_stmts: stmts  */
#line 194 "udf_parser.y"
                         { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1824 "udf_parser.tab.c"
    break;

  case 63: /* stmt: expr ';'  */
#line 197 "udf_parser.y"
                                                          { (yyval.node) = new udf::evaluation_node(LINE, (yyvsp[-1].expression)); }
#line 1830 "udf_parser.tab.c"
    break;

  case 64: /* stmt: tWRITE exprs ';'  */
#line 198 "udf_parser.y"
                                                          { (yyval.node) = new udf::print_node(LINE, (yyvsp[-1].sequence), false); }
#line 1836 "udf_parser.tab.c"
    break;

  case 65: /* stmt: tWRITELN exprs ';'  */
#line 199 "udf_parser.y"
                                                          { (yyval.node) = new udf::print_node(LINE, (yyvsp[-1].sequence), true); }
#line 1842 "udf_parser.tab.c"
    break;

  case 66: /* stmt: tBREAK  */
#line 200 "udf_parser.y"
                                                          { (yyval.node) = new udf::break_node(LINE); }
#line 1848 "udf_parser.tab.c"
    break;

  case 67: /* stmt: tCONTINUE  */
#line 201 "udf_parser.y"
                                                          { (yyval.node) = new udf::continue_node(LINE); }
#line 1854 "udf_parser.tab.c"
    break;

  case 68: /* stmt: return  */
#line 202 "udf_parser.y"
                                                          { (yyval.node) = (yyvsp[0].node); }
#line 1860 "udf_parser.tab.c"
    break;

  case 69: /* stmt: tIF '(' expr ')' stmt  */
#line 203 "udf_parser.y"
                                                          { (yyval.node) = new udf::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1866 "udf_parser.tab.c"
    break;

  case 70: /* stmt: tIF '(' expr ')' stmt iffalse  */
#line 204 "udf_parser.y"
                                                          { (yyval.node) = new udf::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1872 "udf_parser.tab.c"
    break;

  case 71: /* stmt: tFOR '(' opt_forinit ';' opt_exprs ';' opt_exprs ')' stmt  */
#line 205 "udf_parser.y"
                                                                        { (yyval.node) = new udf::for_node(LINE, (yyvsp[-6].sequence), (yyvsp[-4].sequence), (yyvsp[-2].sequence), (yyvsp[0].node)); }
#line 1878 "udf_parser.tab.c"
    break;

  case 72: /* stmt: tUNLESS expr '?' expr ':' tIDENTIFIER expr ';'  */
#line 206 "udf_parser.y"
                                                              { (yyval.node) = new udf::unless_node(LINE, (yyvsp[-6].expression), (yyvsp[-4].expression), *(yyvsp[-2].s), (yyvsp[-1].expression)); delete (yyvsp[-2].s); }
#line 1884 "udf_parser.tab.c"
    break;

  case 73: /* stmt: block  */
#line 207 "udf_parser.y"
                                                          { (yyval.node) = (yyvsp[0].block); }
#line 1890 "udf_parser.tab.c"
    break;

  case 74: /* iffalse: tELSE stmt  */
#line 210 "udf_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 1896 "udf_parser.tab.c"
    break;

  case 75: /* iffalse: tELIF '(' expr ')' stmt  */
#line 211 "udf_parser.y"
                                                  { (yyval.node) = new udf::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1902 "udf_parser.tab.c"
    break;

  case 76: /* iffalse: tELIF '(' expr ')' stmt iffalse  */
#line 212 "udf_parser.y"
                                                  { (yyval.node) = new udf::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1908 "udf_parser.tab.c"
    break;

  case 77: /* expr: integer  */
#line 215 "udf_parser.y"
                                             { (yyval.expression) = (yyvsp[0].expression); }
#line 1914 "udf_parser.tab.c"
    break;

  case 78: /* expr: real  */
#line 216 "udf_parser.y"
                                             { (yyval.expression) = (yyvsp[0].expression); }
#line 1920 "udf_parser.tab.c"
    break;

  case 79: /* expr: string  */
#line 217 "udf_parser.y"
                                             { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1926 "udf_parser.tab.c"
    break;

  case 80: /* expr: tNULLPTR  */
#line 218 "udf_parser.y"
                                             { (yyval.expression) = new udf::nullptr_node(LINE); }
#line 1932 "udf_parser.tab.c"
    break;

  case 81: /* expr: '-' expr  */
#line 219 "udf_parser.y"
                                             { (yyval.expression) = new cdk::unary_minus_node(LINE, (yyvsp[0].expression)); }
#line 1938 "udf_parser.tab.c"
    break;

  case 82: /* expr: '+' expr  */
#line 220 "udf_parser.y"
                                             { (yyval.expression) = new cdk::unary_plus_node(LINE, (yyvsp[0].expression)); }
#line 1944 "udf_parser.tab.c"
    break;

  case 83: /* expr: '~' expr  */
#line 221 "udf_parser.y"
                                             { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 1950 "udf_parser.tab.c"
    break;

  case 84: /* expr: expr '+' expr  */
#line 222 "udf_parser.y"
                                             { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1956 "udf_parser.tab.c"
    break;

  case 85: /* expr: expr '-' expr  */
#line 223 "udf_parser.y"
                                             { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1962 "udf_parser.tab.c"
    break;

  case 86: /* expr: expr '*' expr  */
#line 224 "udf_parser.y"
                                             { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1968 "udf_parser.tab.c"
    break;

  case 87: /* expr: expr '/' expr  */
#line 225 "udf_parser.y"
                                             { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1974 "udf_parser.tab.c"
    break;

  case 88: /* expr: expr '%' expr  */
#line 226 "udf_parser.y"
                                             { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1980 "udf_parser.tab.c"
    break;

  case 89: /* expr: expr '<' expr  */
#line 227 "udf_parser.y"
                                             { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1986 "udf_parser.tab.c"
    break;

  case 90: /* expr: expr '>' expr  */
#line 228 "udf_parser.y"
                                             { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1992 "udf_parser.tab.c"
    break;

  case 91: /* expr: expr tGE expr  */
#line 229 "udf_parser.y"
                                             { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1998 "udf_parser.tab.c"
    break;

  case 92: /* expr: expr tLE expr  */
#line 230 "udf_parser.y"
                                             { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2004 "udf_parser.tab.c"
    break;

  case 93: /* expr: expr tNE expr  */
#line 231 "udf_parser.y"
                                             { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2010 "udf_parser.tab.c"
    break;

  case 94: /* expr: expr tEQ expr  */
#line 232 "udf_parser.y"
                                             { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2016 "udf_parser.tab.c"
    break;

  case 95: /* expr: expr tAND expr  */
#line 233 "udf_parser.y"
                                             { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2022 "udf_parser.tab.c"
    break;

  case 96: /* expr: expr tOR expr  */
#line 234 "udf_parser.y"
                                             { (yyval.expression) = new cdk::or_node (LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2028 "udf_parser.tab.c"
    break;

  case 97: /* expr: tINPUT  */
#line 235 "udf_parser.y"
                                             { (yyval.expression) = new udf::input_node(LINE); }
#line 2034 "udf_parser.tab.c"
    break;

  case 98: /* expr: tSIZEOF '(' expr ')'  */
#line 236 "udf_parser.y"
                                             { (yyval.expression) = new udf::sizeof_node(LINE, (yyvsp[-1].expression)); }
#line 2040 "udf_parser.tab.c"
    break;

  case 99: /* expr: tOBJECTS '(' expr ')'  */
#line 237 "udf_parser.y"
                                             { (yyval.expression) = new udf::stack_alloc_node(LINE, (yyvsp[-1].expression)); }
#line 2046 "udf_parser.tab.c"
    break;

  case 100: /* expr: '(' expr ')'  */
#line 238 "udf_parser.y"
                                             { (yyval.expression) = (yyvsp[-1].expression); }
#line 2052 "udf_parser.tab.c"
    break;

  case 101: /* expr: lval  */
#line 239 "udf_parser.y"
                                             { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 2058 "udf_parser.tab.c"
    break;

  case 102: /* expr: lval '=' expr  */
#line 240 "udf_parser.y"
                                             { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 2064 "udf_parser.tab.c"
    break;

  case 103: /* expr: lval '?'  */
#line 241 "udf_parser.y"
                                             { (yyval.expression) = new udf::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 2070 "udf_parser.tab.c"
    break;

  case 104: /* expr: tensor_expr  */
#line 242 "udf_parser.y"
                                             { (yyval.expression) = (yyvsp[0].expression); }
#line 2076 "udf_parser.tab.c"
    break;

  case 105: /* expr: expr '.' tCAPACITY  */
#line 243 "udf_parser.y"
                                             { (yyval.expression) = new udf::tensor_capacity_node(LINE, (yyvsp[-2].expression)); }
#line 2082 "udf_parser.tab.c"
    break;

  case 106: /* expr: expr '.' tRANK  */
#line 244 "udf_parser.y"
                                             { (yyval.expression) = new udf::tensor_rank_node(LINE, (yyvsp[-2].expression)); }
#line 2088 "udf_parser.tab.c"
    break;

  case 107: /* expr: expr '.' tDIM '(' expr ')'  */
#line 245 "udf_parser.y"
                                             { (yyval.expression) = new udf::tensor_dimension_node(LINE, (yyvsp[-5].expression), (yyvsp[-1].expression)); }
#line 2094 "udf_parser.tab.c"
    break;

  case 108: /* expr: expr '.' tDIMS  */
#line 246 "udf_parser.y"
                                             { (yyval.expression) = new udf::tensor_dimensions_node(LINE, (yyvsp[-2].expression)); }
#line 2100 "udf_parser.tab.c"
    break;

  case 109: /* expr: expr '.' tRESHAPE '(' exprs ')'  */
#line 247 "udf_parser.y"
                                             { (yyval.expression) = new udf::tensor_reshape_node(LINE, (yyvsp[-5].expression), (yyvsp[-1].sequence)); }
#line 2106 "udf_parser.tab.c"
    break;

  case 110: /* expr: expr tCONTRACTION expr  */
#line 248 "udf_parser.y"
                                             { (yyval.expression) = new udf::tensor_contraction_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2112 "udf_parser.tab.c"
    break;

  case 111: /* expr: tIDENTIFIER '(' opt_exprs ')'  */
#line 249 "udf_parser.y"
                                             { (yyval.expression) = new udf::function_call_node(LINE, *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 2118 "udf_parser.tab.c"
    break;

  case 112: /* exprs: expr  */
#line 252 "udf_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression));     }
#line 2124 "udf_parser.tab.c"
    break;

  case 113: /* exprs: exprs ',' expr  */
#line 253 "udf_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 2130 "udf_parser.tab.c"
    break;

  case 114: /* opt_exprs: %empty  */
#line 256 "udf_parser.y"
                          { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 2136 "udf_parser.tab.c"
    break;

  case 115: /* opt_exprs: exprs  */
#line 257 "udf_parser.y"
                          { (yyval.sequence) = (yyvsp[0].sequence); }
#line 2142 "udf_parser.tab.c"
    break;

  case 116: /* tensor_expr: '[' tensor_elems ']'  */
#line 260 "udf_parser.y"
                                               { (yyval.expression) = new udf::tensor_node(LINE, (yyvsp[-1].sequence)); }
#line 2148 "udf_parser.tab.c"
    break;

  case 117: /* tensor_elems: tensor_elem  */
#line 263 "udf_parser.y"
                                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression)); }
#line 2154 "udf_parser.tab.c"
    break;

  case 118: /* tensor_elems: tensor_elems ',' tensor_elem  */
#line 264 "udf_parser.y"
                                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 2160 "udf_parser.tab.c"
    break;

  case 119: /* tensor_elem: expr  */
#line 267 "udf_parser.y"
                               { (yyval.expression) = (yyvsp[0].expression); }
#line 2166 "udf_parser.tab.c"
    break;

  case 120: /* lval: tIDENTIFIER  */
#line 270 "udf_parser.y"
                                                       { (yyval.lvalue) = new cdk::variable_node(LINE, (yyvsp[0].s)); }
#line 2172 "udf_parser.tab.c"
    break;

  case 121: /* lval: expr '@' '(' exprs ')'  */
#line 271 "udf_parser.y"
                                                       { (yyval.lvalue) = new udf::tensor_index_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].sequence)); }
#line 2178 "udf_parser.tab.c"
    break;

  case 122: /* lval: expr '[' expr ']'  */
#line 272 "udf_parser.y"
                                                       { (yyval.lvalue) = new udf::index_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2184 "udf_parser.tab.c"
    break;

  case 123: /* integer: tINTEGER  */
#line 275 "udf_parser.y"
                                          { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 2190 "udf_parser.tab.c"
    break;

  case 124: /* real: tREAL  */
#line 276 "udf_parser.y"
                                          { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 2196 "udf_parser.tab.c"
    break;

  case 125: /* string: tSTRING  */
#line 277 "udf_parser.y"
                                          { (yyval.s) = (yyvsp[0].s); }
#line 2202 "udf_parser.tab.c"
    break;

  case 126: /* string: string tSTRING  */
#line 278 "udf_parser.y"
                                          { (yyval.s) = (yyvsp[-1].s); (yyval.s)->append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2208 "udf_parser.tab.c"
    break;


#line 2212 "udf_parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (compiler, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, compiler);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, compiler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 281 "udf_parser.y"

