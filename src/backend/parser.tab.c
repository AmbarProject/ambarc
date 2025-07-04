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
#line 8 "bison/parser.y"

#include <iostream>
#include <string>
#include <cstdlib>
#include "parser.tab.h"

extern "C++" {
    int yylex(void);
    int yyparse(void);
    extern FILE* yyin;
}
void yyerror(const char *s);
ASTNode* root;

#line 86 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFICADOR = 3,              /* IDENTIFICADOR  */
  YYSYMBOL_NUM_INT = 4,                    /* NUM_INT  */
  YYSYMBOL_NUM_REAL = 5,                   /* NUM_REAL  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_BOOL_TRUE = 7,                  /* BOOL_TRUE  */
  YYSYMBOL_BOOL_FALSE = 8,                 /* BOOL_FALSE  */
  YYSYMBOL_IMPORT = 9,                     /* IMPORT  */
  YYSYMBOL_FUNC = 10,                      /* FUNC  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_FLOAT = 19,                     /* FLOAT  */
  YYSYMBOL_BOOL = 20,                      /* BOOL  */
  YYSYMBOL_STRING_T = 21,                  /* STRING_T  */
  YYSYMBOL_VOID = 22,                      /* VOID  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_NEQ = 26,                       /* NEQ  */
  YYSYMBOL_LT = 27,                        /* LT  */
  YYSYMBOL_LE = 28,                        /* LE  */
  YYSYMBOL_GT = 29,                        /* GT  */
  YYSYMBOL_GE = 30,                        /* GE  */
  YYSYMBOL_ADD = 31,                       /* ADD  */
  YYSYMBOL_SUB = 32,                       /* SUB  */
  YYSYMBOL_MUL = 33,                       /* MUL  */
  YYSYMBOL_DIV = 34,                       /* DIV  */
  YYSYMBOL_ASSIGN = 35,                    /* ASSIGN  */
  YYSYMBOL_ARROW = 36,                     /* ARROW  */
  YYSYMBOL_SEMI = 37,                      /* SEMI  */
  YYSYMBOL_COLON = 38,                     /* COLON  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_DOT = 40,                       /* DOT  */
  YYSYMBOL_LPAREN = 41,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 42,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 43,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 44,                    /* RBRACE  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_programa = 46,                  /* programa  */
  YYSYMBOL_lista_declaracoes = 47,         /* lista_declaracoes  */
  YYSYMBOL_declaracao = 48,                /* declaracao  */
  YYSYMBOL_declaracao_import = 49,         /* declaracao_import  */
  YYSYMBOL_declaracao_variavel = 50,       /* declaracao_variavel  */
  YYSYMBOL_declaracao_funcao = 51,         /* declaracao_funcao  */
  YYSYMBOL_parametros_opt = 52,            /* parametros_opt  */
  YYSYMBOL_parametros = 53,                /* parametros  */
  YYSYMBOL_tipo = 54,                      /* tipo  */
  YYSYMBOL_instrucao = 55,                 /* instrucao  */
  YYSYMBOL_instrucao_atribuicao = 56,      /* instrucao_atribuicao  */
  YYSYMBOL_instrucao_chamada = 57,         /* instrucao_chamada  */
  YYSYMBOL_instrucao_retorno = 58,         /* instrucao_retorno  */
  YYSYMBOL_instrucao_if = 59,              /* instrucao_if  */
  YYSYMBOL_instrucao_while = 60,           /* instrucao_while  */
  YYSYMBOL_instrucao_for = 61,             /* instrucao_for  */
  YYSYMBOL_instrucao_break = 62,           /* instrucao_break  */
  YYSYMBOL_instrucao_continue = 63,        /* instrucao_continue  */
  YYSYMBOL_bloco_codigo = 64,              /* bloco_codigo  */
  YYSYMBOL_lista_instrucao = 65,           /* lista_instrucao  */
  YYSYMBOL_argumentos_opt = 66,            /* argumentos_opt  */
  YYSYMBOL_argumentos = 67,                /* argumentos  */
  YYSYMBOL_expressao = 68,                 /* expressao  */
  YYSYMBOL_expressao_logica = 69,          /* expressao_logica  */
  YYSYMBOL_expressao_relacional = 70,      /* expressao_relacional  */
  YYSYMBOL_expressao_aritmetica = 71,      /* expressao_aritmetica  */
  YYSYMBOL_termo = 72,                     /* termo  */
  YYSYMBOL_fator = 73                      /* fator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    77,    78,    82,    83,    84,    85,    89,
      93,    94,    98,   101,   103,   107,   108,   112,   113,   114,
     115,   116,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   132,   136,   140,   141,   145,   146,   150,   154,   158,
     162,   166,   169,   171,   174,   176,   180,   181,   185,   189,
     190,   191,   195,   196,   197,   198,   199,   200,   201,   205,
     206,   207,   211,   212,   213,   217,   218,   219,   220,   221,
     222,   223
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFICADOR",
  "NUM_INT", "NUM_REAL", "STRING", "BOOL_TRUE", "BOOL_FALSE", "IMPORT",
  "FUNC", "RETURN", "IF", "ELSE", "WHILE", "FOR", "BREAK", "CONTINUE",
  "INT", "FLOAT", "BOOL", "STRING_T", "VOID", "AND", "OR", "EQ", "NEQ",
  "LT", "LE", "GT", "GE", "ADD", "SUB", "MUL", "DIV", "ASSIGN", "ARROW",
  "SEMI", "COLON", "COMMA", "DOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "$accept", "programa", "lista_declaracoes", "declaracao",
  "declaracao_import", "declaracao_variavel", "declaracao_funcao",
  "parametros_opt", "parametros", "tipo", "instrucao",
  "instrucao_atribuicao", "instrucao_chamada", "instrucao_retorno",
  "instrucao_if", "instrucao_while", "instrucao_for", "instrucao_break",
  "instrucao_continue", "bloco_codigo", "lista_instrucao",
  "argumentos_opt", "argumentos", "expressao", "expressao_logica",
  "expressao_relacional", "expressao_aritmetica", "termo", "fator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      27,   -19,    11,    14,    42,   -16,    -1,    17,    16,    29,
     -64,    68,    27,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,    81,    13,    81,
      35,    37,   -64,   -64,   -64,   -64,   -64,   -64,   -64,    81,
      61,    40,   -64,   -21,    41,   -64,    81,    81,    79,   -64,
     -64,    12,   -64,   -64,    64,   -64,   -64,   -64,   -64,   -64,
      24,    60,    65,   -64,   100,    13,    63,   -64,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      66,    67,    71,    81,   -23,   -64,   -64,   -64,    81,   -64,
      70,    81,    73,    69,    74,   109,   -64,   -64,   -64,    45,
      45,    45,    45,    45,    45,    41,    41,   -64,   -64,    72,
      72,    77,    80,   -64,   -64,   -64,    82,    13,   -64,   103,
     -64,    79,   -64,    13,   116,    72,    78,    72,   -64,   -64,
      72,   -64,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,     2,     3,     5,     6,     7,     8,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,    44,
       0,     0,    67,    65,    66,    68,    69,    70,    34,     0,
       0,    48,    49,    52,    59,    62,     0,     0,     0,    39,
      40,     0,     1,     4,     0,    17,    18,    19,    20,    21,
       0,     0,    45,    46,     0,    13,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,    43,    31,     0,    11,
       0,     0,     0,     0,    14,     0,    71,    50,    51,    53,
      54,    55,    56,    57,    58,    60,    61,    63,    64,     0,
       0,     0,     0,    32,    47,     9,     0,     0,    15,    35,
      37,     0,    10,     0,     0,     0,     0,     0,    16,    36,
       0,    12,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,   111,   -64,   -64,   -64,   -64,   -64,   -63,
      75,   -48,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -58,
     -64,   -64,   -64,   -26,   -64,    28,    20,     4,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,    93,    94,    60,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      51,    61,    62,    40,    41,    42,    43,    44,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      83,    54,    95,    63,    70,    71,    72,    73,    74,    75,
      76,    77,    27,    66,    30,    84,    27,    31,    29,    28,
      80,    81,    29,     4,     5,    46,     6,     7,     8,     9,
       1,    55,    56,    57,    58,    59,     2,     3,     4,     5,
      47,     6,     7,     8,     9,    32,    33,    34,    35,    36,
      37,   119,   120,    49,   124,    10,    85,   111,    48,    88,
     127,    89,   112,    68,    69,   114,    50,   129,    52,   131,
      10,    64,   132,   126,    78,    79,    76,    77,    65,    38,
     105,   106,    82,    39,    32,    33,    34,    35,    36,    37,
      99,   100,   101,   102,   103,   104,    97,    98,    67,   107,
     108,    87,    90,    92,    91,    96,    27,   113,   109,   110,
     115,   116,   118,   117,   121,    10,   125,   122,   123,   128,
     130,     0,    39,    53,     0,     0,    86
};

static const yytype_int16 yycheck[] =
{
      48,    27,    65,    29,    25,    26,    27,    28,    29,    30,
      31,    32,    35,    39,     3,     3,    35,     3,    41,    38,
      46,    47,    41,    11,    12,    41,    14,    15,    16,    17,
       3,    18,    19,    20,    21,    22,     9,    10,    11,    12,
      41,    14,    15,    16,    17,     3,     4,     5,     6,     7,
       8,   109,   110,    37,   117,    43,    44,    83,    41,    35,
     123,    37,    88,    23,    24,    91,    37,   125,     0,   127,
      43,    36,   130,   121,    33,    34,    31,    32,    41,    37,
      76,    77,     3,    41,     3,     4,     5,     6,     7,     8,
      70,    71,    72,    73,    74,    75,    68,    69,    37,    78,
      79,    37,    42,     3,    39,    42,    35,    37,    42,    42,
      37,    42,     3,    39,    37,    43,    13,    37,    36,     3,
      42,    -1,    41,    12,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     9,    10,    11,    12,    14,    15,    16,    17,
      43,    46,    47,    48,    49,    50,    51,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    35,    38,    41,
       3,     3,     3,     4,     5,     6,     7,     8,    37,    41,
      68,    69,    70,    71,    72,    73,    41,    41,    41,    37,
      37,    65,     0,    48,    68,    18,    19,    20,    21,    22,
      54,    66,    67,    68,    36,    41,    68,    37,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      68,    68,     3,    56,     3,    44,    55,    37,    35,    37,
      42,    39,     3,    52,    53,    54,    42,    70,    70,    71,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    42,
      42,    68,    68,    37,    68,    37,    42,    39,     3,    64,
      64,    37,    37,    36,    54,    13,    56,    54,     3,    64,
      42,    64,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    49,
      50,    50,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    57,    58,    58,    59,    59,    60,    61,    62,
      63,    64,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     5,
       6,     4,     8,     0,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     3,     2,     5,     7,     5,     8,     2,
       2,     3,     0,     2,     0,     1,     1,     3,     1,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     3
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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
yyparse (void)
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
  case 2: /* programa: lista_declaracoes  */
#line 73 "bison/parser.y"
                      { root = (yyvsp[0].node); }
#line 1236 "parser.tab.c"
    break;

  case 3: /* lista_declaracoes: declaracao  */
#line 77 "bison/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1242 "parser.tab.c"
    break;

  case 4: /* lista_declaracoes: lista_declaracoes declaracao  */
#line 78 "bison/parser.y"
                                   { (yyval.node) = (yyvsp[0].node) ? (yyvsp[0].node) : (yyvsp[-1].node); }
#line 1248 "parser.tab.c"
    break;

  case 5: /* declaracao: declaracao_import  */
#line 82 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1254 "parser.tab.c"
    break;

  case 6: /* declaracao: declaracao_variavel  */
#line 83 "bison/parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1260 "parser.tab.c"
    break;

  case 7: /* declaracao: declaracao_funcao  */
#line 84 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1266 "parser.tab.c"
    break;

  case 8: /* declaracao: instrucao  */
#line 85 "bison/parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1272 "parser.tab.c"
    break;

  case 10: /* declaracao_variavel: IDENTIFICADOR COLON tipo ASSIGN expressao SEMI  */
#line 93 "bison/parser.y"
                                                   { (yyval.node) = new VarDecl((yyvsp[-5].id), *(yyvsp[-3].str), (yyvsp[-1].node)); }
#line 1278 "parser.tab.c"
    break;

  case 11: /* declaracao_variavel: IDENTIFICADOR COLON tipo SEMI  */
#line 94 "bison/parser.y"
                                    { (yyval.node) = new VarDecl((yyvsp[-3].id), *(yyvsp[-1].str), nullptr); }
#line 1284 "parser.tab.c"
    break;

  case 17: /* tipo: INT  */
#line 112 "bison/parser.y"
                { (yyval.str) = new std::string("int"); }
#line 1290 "parser.tab.c"
    break;

  case 18: /* tipo: FLOAT  */
#line 113 "bison/parser.y"
                { (yyval.str) = new std::string("float"); }
#line 1296 "parser.tab.c"
    break;

  case 19: /* tipo: BOOL  */
#line 114 "bison/parser.y"
                { (yyval.str) = new std::string("bool"); }
#line 1302 "parser.tab.c"
    break;

  case 20: /* tipo: STRING_T  */
#line 115 "bison/parser.y"
                {(yyval.str) = new std::string("string"); }
#line 1308 "parser.tab.c"
    break;

  case 21: /* tipo: VOID  */
#line 116 "bison/parser.y"
                { (yyval.str) = new std::string("void"); }
#line 1314 "parser.tab.c"
    break;

  case 22: /* instrucao: instrucao_atribuicao  */
#line 120 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1320 "parser.tab.c"
    break;

  case 23: /* instrucao: instrucao_chamada  */
#line 121 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1326 "parser.tab.c"
    break;

  case 24: /* instrucao: instrucao_retorno  */
#line 122 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1332 "parser.tab.c"
    break;

  case 25: /* instrucao: instrucao_if  */
#line 123 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1338 "parser.tab.c"
    break;

  case 26: /* instrucao: instrucao_while  */
#line 124 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1344 "parser.tab.c"
    break;

  case 27: /* instrucao: instrucao_for  */
#line 125 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1350 "parser.tab.c"
    break;

  case 28: /* instrucao: instrucao_break  */
#line 126 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1356 "parser.tab.c"
    break;

  case 29: /* instrucao: instrucao_continue  */
#line 127 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1362 "parser.tab.c"
    break;

  case 30: /* instrucao: bloco_codigo  */
#line 128 "bison/parser.y"
                                { (yyval.node) = nullptr; }
#line 1368 "parser.tab.c"
    break;

  case 48: /* expressao: expressao_logica  */
#line 185 "bison/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1374 "parser.tab.c"
    break;

  case 49: /* expressao_logica: expressao_relacional  */
#line 189 "bison/parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1380 "parser.tab.c"
    break;

  case 50: /* expressao_logica: expressao_logica AND expressao_relacional  */
#line 190 "bison/parser.y"
                                                { (yyval.node) = new BinaryExpr("AND", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1386 "parser.tab.c"
    break;

  case 51: /* expressao_logica: expressao_logica OR expressao_relacional  */
#line 191 "bison/parser.y"
                                               { (yyval.node) = new BinaryExpr("OR", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1392 "parser.tab.c"
    break;

  case 52: /* expressao_relacional: expressao_aritmetica  */
#line 195 "bison/parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1398 "parser.tab.c"
    break;

  case 53: /* expressao_relacional: expressao_aritmetica EQ expressao_aritmetica  */
#line 196 "bison/parser.y"
                                                   { (yyval.node) = new BinaryExpr("==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1404 "parser.tab.c"
    break;

  case 54: /* expressao_relacional: expressao_aritmetica NEQ expressao_aritmetica  */
#line 197 "bison/parser.y"
                                                    { (yyval.node) = new BinaryExpr("!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1410 "parser.tab.c"
    break;

  case 55: /* expressao_relacional: expressao_aritmetica LT expressao_aritmetica  */
#line 198 "bison/parser.y"
                                                   { (yyval.node) = new BinaryExpr("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1416 "parser.tab.c"
    break;

  case 56: /* expressao_relacional: expressao_aritmetica LE expressao_aritmetica  */
#line 199 "bison/parser.y"
                                                   { (yyval.node) = new BinaryExpr("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1422 "parser.tab.c"
    break;

  case 57: /* expressao_relacional: expressao_aritmetica GT expressao_aritmetica  */
#line 200 "bison/parser.y"
                                                   { (yyval.node) = new BinaryExpr(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1428 "parser.tab.c"
    break;

  case 58: /* expressao_relacional: expressao_aritmetica GE expressao_aritmetica  */
#line 201 "bison/parser.y"
                                                   { (yyval.node) = new BinaryExpr(">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1434 "parser.tab.c"
    break;

  case 59: /* expressao_aritmetica: termo  */
#line 205 "bison/parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1440 "parser.tab.c"
    break;

  case 60: /* expressao_aritmetica: expressao_aritmetica ADD termo  */
#line 206 "bison/parser.y"
                                     { (yyval.node) = new BinaryExpr("+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1446 "parser.tab.c"
    break;

  case 61: /* expressao_aritmetica: expressao_aritmetica SUB termo  */
#line 207 "bison/parser.y"
                                     { (yyval.node) = new BinaryExpr("-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1452 "parser.tab.c"
    break;

  case 62: /* termo: fator  */
#line 211 "bison/parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1458 "parser.tab.c"
    break;

  case 63: /* termo: termo MUL fator  */
#line 212 "bison/parser.y"
                      { (yyval.node) = new BinaryExpr("*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1464 "parser.tab.c"
    break;

  case 64: /* termo: termo DIV fator  */
#line 213 "bison/parser.y"
                      { (yyval.node) = new BinaryExpr("/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1470 "parser.tab.c"
    break;

  case 65: /* fator: NUM_INT  */
#line 217 "bison/parser.y"
              { (yyval.node) = new NumberExpr((yyvsp[0].num)); }
#line 1476 "parser.tab.c"
    break;

  case 66: /* fator: NUM_REAL  */
#line 218 "bison/parser.y"
               { (yyval.node) = new NumberExpr((yyvsp[0].real)); }
#line 1482 "parser.tab.c"
    break;

  case 67: /* fator: IDENTIFICADOR  */
#line 219 "bison/parser.y"
                    { (yyval.node) = nullptr; }
#line 1488 "parser.tab.c"
    break;

  case 68: /* fator: STRING  */
#line 220 "bison/parser.y"
             { (yyval.node) = nullptr; }
#line 1494 "parser.tab.c"
    break;

  case 69: /* fator: BOOL_TRUE  */
#line 221 "bison/parser.y"
                { (yyval.node) = nullptr; }
#line 1500 "parser.tab.c"
    break;

  case 70: /* fator: BOOL_FALSE  */
#line 222 "bison/parser.y"
                 { (yyval.node) = nullptr; }
#line 1506 "parser.tab.c"
    break;

  case 71: /* fator: LPAREN expressao RPAREN  */
#line 223 "bison/parser.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 1512 "parser.tab.c"
    break;


#line 1516 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 230 "bison/parser.y"


void yyerror(const char *s) {
    std::cerr << "Erro de sintaxe: " << s << std::endl;
}
