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
#line 25 "bison/parser.y"

#include <iostream>
#include <string>
#include <cstdlib>
#include "parser.tab.h"

extern "C++" {
    int yylex(void);
    int yyparse(void);
    extern FILE* yyin;
    extern int yylineno;
}

void yyerror(const char *s) {
    std::cerr << "Error at line " << yylineno << ": " << s << std::endl;
}

ASTNode* root = nullptr;

// Helper function to create parameter lists
std::vector<std::pair<std::string, std::string>>* createParamList(std::string* type, char* id) {
    auto params = new std::vector<std::pair<std::string, std::string>>();
    params->push_back({*type, id});
    delete type;
    return params;
}

#line 99 "y.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "bison/parser.y"

    #include "ast/AST.hpp"
    #include "ast/BinaryExpr.hpp"
    #include "ast/NumberExpr.hpp"
    #include "ast/StringExpr.hpp"
    #include "ast/BoolExpr.hpp"
    #include "ast/IdentifierExpr.hpp"
    #include "ast/VarDecl.hpp"
    #include "ast/Program.hpp"
    #include "ast/AssignStmt.hpp"
    #include "ast/Block.hpp"
    #include "ast/IfStmt.hpp"
    #include "ast/WhileStmt.hpp"
    #include "ast/ReturnStmt.hpp"
    #include "ast/CallExpr.hpp"
    #include "ast/FunctionDecl.hpp"
    #include "ast/BreakStmt.hpp"
    #include "ast/ContinueStmt.hpp"
    #include "ast/ForStmt.hpp"
    #include <vector>
    #include <string>
    extern ASTNode* root;

#line 155 "y.tab.c"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    NUM_INT = 259,                 /* NUM_INT  */
    NUM_REAL = 260,                /* NUM_REAL  */
    STRING = 261,                  /* STRING  */
    BOOL_TRUE = 262,               /* BOOL_TRUE  */
    BOOL_FALSE = 263,              /* BOOL_FALSE  */
    IMPORT = 264,                  /* IMPORT  */
    FUNC = 265,                    /* FUNC  */
    RETURN = 266,                  /* RETURN  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    WHILE = 269,                   /* WHILE  */
    FOR = 270,                     /* FOR  */
    BREAK = 271,                   /* BREAK  */
    CONTINUE = 272,                /* CONTINUE  */
    INT = 273,                     /* INT  */
    FLOAT = 274,                   /* FLOAT  */
    BOOL = 275,                    /* BOOL  */
    STRING_T = 276,                /* STRING_T  */
    VOID = 277,                    /* VOID  */
    AND = 278,                     /* AND  */
    OR = 279,                      /* OR  */
    EQ = 280,                      /* EQ  */
    NEQ = 281,                     /* NEQ  */
    LT = 282,                      /* LT  */
    LE = 283,                      /* LE  */
    GT = 284,                      /* GT  */
    GE = 285,                      /* GE  */
    ADD = 286,                     /* ADD  */
    SUB = 287,                     /* SUB  */
    MUL = 288,                     /* MUL  */
    DIV = 289,                     /* DIV  */
    ASSIGN = 290,                  /* ASSIGN  */
    ARROW = 291,                   /* ARROW  */
    SEMI = 292,                    /* SEMI  */
    COLON = 293,                   /* COLON  */
    COMMA = 294,                   /* COMMA  */
    DOT = 295,                     /* DOT  */
    LPAREN = 296,                  /* LPAREN  */
    RPAREN = 297,                  /* RPAREN  */
    LBRACE = 298,                  /* LBRACE  */
    RBRACE = 299                   /* RBRACE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define NUM_INT 259
#define NUM_REAL 260
#define STRING 261
#define BOOL_TRUE 262
#define BOOL_FALSE 263
#define IMPORT 264
#define FUNC 265
#define RETURN 266
#define IF 267
#define ELSE 268
#define WHILE 269
#define FOR 270
#define BREAK 271
#define CONTINUE 272
#define INT 273
#define FLOAT 274
#define BOOL 275
#define STRING_T 276
#define VOID 277
#define AND 278
#define OR 279
#define EQ 280
#define NEQ 281
#define LT 282
#define LE 283
#define GT 284
#define GE 285
#define ADD 286
#define SUB 287
#define MUL 288
#define DIV 289
#define ASSIGN 290
#define ARROW 291
#define SEMI 292
#define COLON 293
#define COMMA 294
#define DOT 295
#define LPAREN 296
#define RPAREN 297
#define LBRACE 298
#define RBRACE 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "bison/parser.y"

    int num;
    float real;
    bool bval;
    char* id;
    ASTNode* node;
    std::string* str;
    std::vector<ASTNode*>* stmts;
    std::vector<std::pair<std::string, std::string>>* params;

#line 274 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
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
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_decl_list = 47,                 /* decl_list  */
  YYSYMBOL_decl = 48,                      /* decl  */
  YYSYMBOL_import_decl = 49,               /* import_decl  */
  YYSYMBOL_var_decl = 50,                  /* var_decl  */
  YYSYMBOL_func_decl = 51,                 /* func_decl  */
  YYSYMBOL_opt_params = 52,                /* opt_params  */
  YYSYMBOL_params = 53,                    /* params  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_stmt = 55,                      /* stmt  */
  YYSYMBOL_assign_stmt = 56,               /* assign_stmt  */
  YYSYMBOL_call_stmt = 57,                 /* call_stmt  */
  YYSYMBOL_return_stmt = 58,               /* return_stmt  */
  YYSYMBOL_if_stmt = 59,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 60,                /* while_stmt  */
  YYSYMBOL_for_stmt = 61,                  /* for_stmt  */
  YYSYMBOL_break_stmt = 62,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 63,             /* continue_stmt  */
  YYSYMBOL_block = 64,                     /* block  */
  YYSYMBOL_stmt_list = 65,                 /* stmt_list  */
  YYSYMBOL_opt_args = 66,                  /* opt_args  */
  YYSYMBOL_args = 67,                      /* args  */
  YYSYMBOL_expr = 68,                      /* expr  */
  YYSYMBOL_logic_expr = 69,                /* logic_expr  */
  YYSYMBOL_rel_expr = 70,                  /* rel_expr  */
  YYSYMBOL_arith_expr = 71,                /* arith_expr  */
  YYSYMBOL_term = 72,                      /* term  */
  YYSYMBOL_factor = 73,                    /* factor  */
  YYSYMBOL_func_call = 74                  /* func_call  */
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
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

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
static const yytype_int16 yyrline[] =
{
       0,    91,    91,   102,   107,   115,   116,   117,   118,   122,
     126,   130,   137,   146,   147,   151,   152,   160,   161,   162,
     163,   164,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   180,   184,   188,   189,   193,   196,   202,   208,   214,
     218,   222,   225,   238,   242,   249,   250,   254,   255,   259,
     263,   264,   265,   269,   270,   271,   272,   273,   274,   275,
     279,   280,   281,   285,   286,   287,   291,   292,   293,   294,
     295,   296,   297,   298,   302
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "NUM_INT", "NUM_REAL", "STRING", "BOOL_TRUE", "BOOL_FALSE", "IMPORT",
  "FUNC", "RETURN", "IF", "ELSE", "WHILE", "FOR", "BREAK", "CONTINUE",
  "INT", "FLOAT", "BOOL", "STRING_T", "VOID", "AND", "OR", "EQ", "NEQ",
  "LT", "LE", "GT", "GE", "ADD", "SUB", "MUL", "DIV", "ASSIGN", "ARROW",
  "SEMI", "COLON", "COMMA", "DOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "$accept", "program", "decl_list", "decl", "import_decl", "var_decl",
  "func_decl", "opt_params", "params", "type", "stmt", "assign_stmt",
  "call_stmt", "return_stmt", "if_stmt", "while_stmt", "for_stmt",
  "break_stmt", "continue_stmt", "block", "stmt_list", "opt_args", "args",
  "expr", "logic_expr", "rel_expr", "arith_expr", "term", "factor",
  "func_call", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      69,    -1,    32,    42,    84,    16,    18,    20,    45,    72,
      12,    65,    69,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,    73,    90,    28,
      90,    -4,    70,    75,   -99,   -99,   -99,   -99,   -99,   -99,
      90,    76,    29,   -99,    74,    30,   -99,   -99,    90,    90,
     111,   -99,   -99,   -16,   -99,   -99,    27,   -99,   -99,   -99,
      78,   -99,   -99,   -99,   -99,   -99,   -17,    77,    79,   -99,
     114,    28,    80,   -99,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    81,    82,    85,    90,
     -99,   -99,   -99,    90,   -99,   -99,    90,    89,    86,    88,
     126,   -99,   -99,   -99,    36,    36,    36,    36,    36,    36,
      30,    30,   -99,   -99,    87,    87,    95,    96,   -99,   -99,
      98,    28,   -99,   122,   -99,   111,   -99,    28,   133,    87,
      97,    87,   -99,   -99,    87,   -99,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     5,     6,     7,     8,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,     0,
      45,     0,     0,    68,    66,    67,    69,    70,    71,    34,
       0,     0,    49,    50,    53,    60,    63,    72,     0,     0,
       0,    39,    40,     0,    41,    43,     0,     1,     4,    32,
       0,    17,    18,    19,    20,    21,     0,     0,    46,    47,
       0,    13,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    44,    31,     0,    11,    74,     0,     0,     0,    14,
       0,    73,    51,    52,    54,    55,    56,    57,    58,    59,
      61,    62,    64,    65,     0,     0,     0,     0,    48,     9,
       0,     0,    15,    35,    37,     0,    10,     0,     0,     0,
       0,     0,    16,    36,     0,    12,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   -99,   125,   -99,   -99,   -99,   -99,   -99,   -67,
      -5,   -50,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -98,
     -99,   -99,   -99,   -27,   -99,    33,   -70,    -9,    -8,     2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,    98,    99,    66,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      56,    67,    68,    41,    42,    43,    44,    45,    46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      89,    60,    27,    69,   100,    55,   104,   105,   106,   107,
     108,   109,    27,    72,    27,    53,   123,   124,    93,    28,
      94,    86,    87,     4,     5,    30,     6,     7,     8,     9,
      53,   133,    70,   135,    28,    31,   136,    29,     4,     5,
      30,     6,     7,     8,     9,    32,    61,    62,    63,    64,
      65,    91,    74,    75,   128,    10,    54,    48,    27,    49,
     131,    50,   116,    84,    85,    57,   117,    82,    83,   118,
      10,    90,     1,   110,   111,   130,   112,   113,     2,     3,
       4,     5,    51,     6,     7,     8,     9,    33,    34,    35,
      36,    37,    38,    33,    34,    35,    36,    37,    38,    76,
      77,    78,    79,    80,    81,    82,    83,   102,   103,    52,
      59,    71,    10,    73,    88,    92,    30,    97,    96,    95,
      28,    39,   101,   114,   115,    40,   119,   121,   120,   122,
      10,    40,   125,   126,   127,   129,   132,    58,     0,   134
};

static const yytype_int16 yycheck[] =
{
      50,    28,     0,    30,    71,    10,    76,    77,    78,    79,
      80,    81,    10,    40,    12,     3,   114,   115,    35,    35,
      37,    48,    49,    11,    12,    41,    14,    15,    16,    17,
       3,   129,    36,   131,    35,     3,   134,    38,    11,    12,
      41,    14,    15,    16,    17,     3,    18,    19,    20,    21,
      22,    56,    23,    24,   121,    43,    44,    41,    56,    41,
     127,    41,    89,    33,    34,     0,    93,    31,    32,    96,
      43,    44,     3,    82,    83,   125,    84,    85,     9,    10,
      11,    12,    37,    14,    15,    16,    17,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    25,
      26,    27,    28,    29,    30,    31,    32,    74,    75,    37,
      37,    41,    43,    37,     3,    37,    41,     3,    39,    42,
      35,    37,    42,    42,    42,    41,    37,    39,    42,     3,
      43,    41,    37,    37,    36,    13,     3,    12,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     9,    10,    11,    12,    14,    15,    16,    17,
      43,    46,    47,    48,    49,    50,    51,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    74,    35,    38,
      41,     3,     3,     3,     4,     5,     6,     7,     8,    37,
      41,    68,    69,    70,    71,    72,    73,    74,    41,    41,
      41,    37,    37,     3,    44,    55,    65,     0,    48,    37,
      68,    18,    19,    20,    21,    22,    54,    66,    67,    68,
      36,    41,    68,    37,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    68,    68,     3,    56,
      44,    55,    37,    35,    37,    42,    39,     3,    52,    53,
      54,    42,    70,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    42,    42,    68,    68,    68,    37,
      42,    39,     3,    64,    64,    37,    37,    36,    54,    13,
      56,    54,     3,    64,    42,    64,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    49,
      50,    50,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    57,    58,    58,    59,    59,    60,    61,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    71,    72,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     5,
       6,     4,     8,     0,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     3,     2,     5,     7,     5,     8,     2,
       2,     2,     3,     1,     2,     0,     1,     1,     3,     1,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     4
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
  case 2: /* program: decl_list  */
#line 91 "bison/parser.y"
              {
        Program* prog = dynamic_cast<Program*>((yyvsp[0].node));
        if (!prog) {
            prog = new Program();
            prog->add((yyvsp[0].node));
        }
        root = prog;
    }
#line 1424 "y.tab.c"
    break;

  case 3: /* decl_list: decl  */
#line 102 "bison/parser.y"
           {
          Program* p = new Program();
          p->add((yyvsp[0].node));
          (yyval.node) = p;
      }
#line 1434 "y.tab.c"
    break;

  case 4: /* decl_list: decl_list decl  */
#line 107 "bison/parser.y"
                     {
          Program* p = dynamic_cast<Program*>((yyvsp[-1].node));
          p->add((yyvsp[0].node));
          (yyval.node) = p;
      }
#line 1444 "y.tab.c"
    break;

  case 5: /* decl: import_decl  */
#line 115 "bison/parser.y"
                          { (yyval.node) = nullptr; }
#line 1450 "y.tab.c"
    break;

  case 6: /* decl: var_decl  */
#line 116 "bison/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1456 "y.tab.c"
    break;

  case 7: /* decl: func_decl  */
#line 117 "bison/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1462 "y.tab.c"
    break;

  case 8: /* decl: stmt  */
#line 118 "bison/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1468 "y.tab.c"
    break;

  case 9: /* import_decl: IMPORT IDENTIFIER ARROW IDENTIFIER SEMI  */
#line 122 "bison/parser.y"
                                            { (yyval.node) = nullptr; }
#line 1474 "y.tab.c"
    break;

  case 10: /* var_decl: IDENTIFIER COLON type ASSIGN expr SEMI  */
#line 126 "bison/parser.y"
                                             { 
          (yyval.node) = new VarDecl(std::string((yyvsp[-5].id)), *(yyvsp[-3].str), (yyvsp[-1].node)); 
          delete (yyvsp[-3].str);
      }
#line 1483 "y.tab.c"
    break;

  case 11: /* var_decl: IDENTIFIER COLON type SEMI  */
#line 130 "bison/parser.y"
                                 { 
          (yyval.node) = new VarDecl(std::string((yyvsp[-3].id)), *(yyvsp[-1].str), nullptr);
          delete (yyvsp[-1].str);
      }
#line 1492 "y.tab.c"
    break;

  case 12: /* func_decl: FUNC IDENTIFIER LPAREN opt_params RPAREN ARROW type block  */
#line 137 "bison/parser.y"
                                                              {
        (yyval.node) = new FunctionDecl(std::string((yyvsp[-6].id)), *(yyvsp[-1].str), (yyvsp[-4].params) ? *(yyvsp[-4].params) : std::vector<std::pair<std::string, std::string>>(), 
                             dynamic_cast<Block*>((yyvsp[0].node)));
        delete (yyvsp[-4].params);
        delete (yyvsp[-1].str);
    }
#line 1503 "y.tab.c"
    break;

  case 13: /* opt_params: %empty  */
#line 146 "bison/parser.y"
      { (yyval.params) = nullptr; }
#line 1509 "y.tab.c"
    break;

  case 14: /* opt_params: params  */
#line 147 "bison/parser.y"
             { (yyval.params) = (yyvsp[0].params); }
#line 1515 "y.tab.c"
    break;

  case 15: /* params: type IDENTIFIER  */
#line 151 "bison/parser.y"
                      { (yyval.params) = createParamList((yyvsp[-1].str), (yyvsp[0].id)); }
#line 1521 "y.tab.c"
    break;

  case 16: /* params: params COMMA type IDENTIFIER  */
#line 152 "bison/parser.y"
                                   { 
          (yyvsp[-3].params)->push_back({*(yyvsp[-1].str), (yyvsp[0].id)});
          delete (yyvsp[-1].str);
          (yyval.params) = (yyvsp[-3].params);
      }
#line 1531 "y.tab.c"
    break;

  case 17: /* type: INT  */
#line 160 "bison/parser.y"
              { (yyval.str) = new std::string("int"); }
#line 1537 "y.tab.c"
    break;

  case 18: /* type: FLOAT  */
#line 161 "bison/parser.y"
              { (yyval.str) = new std::string("float"); }
#line 1543 "y.tab.c"
    break;

  case 19: /* type: BOOL  */
#line 162 "bison/parser.y"
              { (yyval.str) = new std::string("bool"); }
#line 1549 "y.tab.c"
    break;

  case 20: /* type: STRING_T  */
#line 163 "bison/parser.y"
              { (yyval.str) = new std::string("string"); }
#line 1555 "y.tab.c"
    break;

  case 21: /* type: VOID  */
#line 164 "bison/parser.y"
              { (yyval.str) = new std::string("void"); }
#line 1561 "y.tab.c"
    break;

  case 22: /* stmt: assign_stmt  */
#line 168 "bison/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1567 "y.tab.c"
    break;

  case 23: /* stmt: call_stmt  */
#line 169 "bison/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1573 "y.tab.c"
    break;

  case 24: /* stmt: return_stmt  */
#line 170 "bison/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1579 "y.tab.c"
    break;

  case 25: /* stmt: if_stmt  */
#line 171 "bison/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1585 "y.tab.c"
    break;

  case 26: /* stmt: while_stmt  */
#line 172 "bison/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1591 "y.tab.c"
    break;

  case 27: /* stmt: for_stmt  */
#line 173 "bison/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1597 "y.tab.c"
    break;

  case 28: /* stmt: break_stmt  */
#line 174 "bison/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1603 "y.tab.c"
    break;

  case 29: /* stmt: continue_stmt  */
#line 175 "bison/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1609 "y.tab.c"
    break;

  case 30: /* stmt: block  */
#line 176 "bison/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1615 "y.tab.c"
    break;

  case 31: /* assign_stmt: IDENTIFIER ASSIGN expr SEMI  */
#line 180 "bison/parser.y"
                                { (yyval.node) = new AssignStmt((yyvsp[-3].id), (yyvsp[-1].node)); }
#line 1621 "y.tab.c"
    break;

  case 32: /* call_stmt: func_call SEMI  */
#line 184 "bison/parser.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 1627 "y.tab.c"
    break;

  case 33: /* return_stmt: RETURN expr SEMI  */
#line 188 "bison/parser.y"
                       { (yyval.node) = new ReturnStmt((yyvsp[-1].node)); }
#line 1633 "y.tab.c"
    break;

  case 34: /* return_stmt: RETURN SEMI  */
#line 189 "bison/parser.y"
                  { (yyval.node) = new ReturnStmt(); }
#line 1639 "y.tab.c"
    break;

  case 35: /* if_stmt: IF LPAREN expr RPAREN block  */
#line 193 "bison/parser.y"
                                  {
          (yyval.node) = new IfStmt((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 1647 "y.tab.c"
    break;

  case 36: /* if_stmt: IF LPAREN expr RPAREN block ELSE block  */
#line 196 "bison/parser.y"
                                             {
          (yyval.node) = new IfStmt((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
      }
#line 1655 "y.tab.c"
    break;

  case 37: /* while_stmt: WHILE LPAREN expr RPAREN block  */
#line 202 "bison/parser.y"
                                   {
        (yyval.node) = new WhileStmt((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1663 "y.tab.c"
    break;

  case 38: /* for_stmt: FOR LPAREN assign_stmt expr SEMI assign_stmt RPAREN block  */
#line 208 "bison/parser.y"
                                                              {
        (yyval.node) = new ForStmt((yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-2].node), dynamic_cast<Block*>((yyvsp[0].node)));
    }
#line 1671 "y.tab.c"
    break;

  case 39: /* break_stmt: BREAK SEMI  */
#line 214 "bison/parser.y"
               { (yyval.node) = new BreakStmt(); }
#line 1677 "y.tab.c"
    break;

  case 40: /* continue_stmt: CONTINUE SEMI  */
#line 218 "bison/parser.y"
                  { (yyval.node) = new ContinueStmt(); }
#line 1683 "y.tab.c"
    break;

  case 41: /* block: LBRACE RBRACE  */
#line 222 "bison/parser.y"
                  {
        (yyval.node) = new Block();
    }
#line 1691 "y.tab.c"
    break;

  case 42: /* block: LBRACE stmt_list RBRACE  */
#line 225 "bison/parser.y"
                              {
        Block* blk = new Block();
        if ((yyvsp[-1].stmts)) {
            for (ASTNode* stmt : *(yyvsp[-1].stmts)) {
                blk->add(stmt);
            }
            delete (yyvsp[-1].stmts);
        }
        (yyval.node) = blk;
    }
#line 1706 "y.tab.c"
    break;

  case 43: /* stmt_list: stmt  */
#line 238 "bison/parser.y"
           {
        (yyval.stmts) = new std::vector<ASTNode*>();
        if ((yyvsp[0].node)) (yyval.stmts)->push_back((yyvsp[0].node));
      }
#line 1715 "y.tab.c"
    break;

  case 44: /* stmt_list: stmt_list stmt  */
#line 242 "bison/parser.y"
                     {
        if ((yyvsp[0].node)) (yyvsp[-1].stmts)->push_back((yyvsp[0].node));
        (yyval.stmts) = (yyvsp[-1].stmts);
      }
#line 1724 "y.tab.c"
    break;

  case 45: /* opt_args: %empty  */
#line 249 "bison/parser.y"
      { (yyval.stmts) = new std::vector<ASTNode*>(); }
#line 1730 "y.tab.c"
    break;

  case 46: /* opt_args: args  */
#line 250 "bison/parser.y"
           { (yyval.stmts) = (yyvsp[0].stmts); }
#line 1736 "y.tab.c"
    break;

  case 47: /* args: expr  */
#line 254 "bison/parser.y"
           { (yyval.stmts) = new std::vector<ASTNode*>(); (yyval.stmts)->push_back((yyvsp[0].node)); }
#line 1742 "y.tab.c"
    break;

  case 48: /* args: args COMMA expr  */
#line 255 "bison/parser.y"
                      { (yyvsp[-2].stmts)->push_back((yyvsp[0].node)); (yyval.stmts) = (yyvsp[-2].stmts); }
#line 1748 "y.tab.c"
    break;

  case 49: /* expr: logic_expr  */
#line 259 "bison/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1754 "y.tab.c"
    break;

  case 50: /* logic_expr: rel_expr  */
#line 263 "bison/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1760 "y.tab.c"
    break;

  case 51: /* logic_expr: logic_expr AND rel_expr  */
#line 264 "bison/parser.y"
                              { (yyval.node) = new BinaryExpr("AND", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1766 "y.tab.c"
    break;

  case 52: /* logic_expr: logic_expr OR rel_expr  */
#line 265 "bison/parser.y"
                             { (yyval.node) = new BinaryExpr("OR", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1772 "y.tab.c"
    break;

  case 53: /* rel_expr: arith_expr  */
#line 269 "bison/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1778 "y.tab.c"
    break;

  case 54: /* rel_expr: arith_expr EQ arith_expr  */
#line 270 "bison/parser.y"
                               { (yyval.node) = new BinaryExpr("==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1784 "y.tab.c"
    break;

  case 55: /* rel_expr: arith_expr NEQ arith_expr  */
#line 271 "bison/parser.y"
                                { (yyval.node) = new BinaryExpr("!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1790 "y.tab.c"
    break;

  case 56: /* rel_expr: arith_expr LT arith_expr  */
#line 272 "bison/parser.y"
                               { (yyval.node) = new BinaryExpr("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1796 "y.tab.c"
    break;

  case 57: /* rel_expr: arith_expr LE arith_expr  */
#line 273 "bison/parser.y"
                               { (yyval.node) = new BinaryExpr("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1802 "y.tab.c"
    break;

  case 58: /* rel_expr: arith_expr GT arith_expr  */
#line 274 "bison/parser.y"
                               { (yyval.node) = new BinaryExpr(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1808 "y.tab.c"
    break;

  case 59: /* rel_expr: arith_expr GE arith_expr  */
#line 275 "bison/parser.y"
                               { (yyval.node) = new BinaryExpr(">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1814 "y.tab.c"
    break;

  case 60: /* arith_expr: term  */
#line 279 "bison/parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1820 "y.tab.c"
    break;

  case 61: /* arith_expr: arith_expr ADD term  */
#line 280 "bison/parser.y"
                          { (yyval.node) = new BinaryExpr("+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1826 "y.tab.c"
    break;

  case 62: /* arith_expr: arith_expr SUB term  */
#line 281 "bison/parser.y"
                          { (yyval.node) = new BinaryExpr("-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1832 "y.tab.c"
    break;

  case 63: /* term: factor  */
#line 285 "bison/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1838 "y.tab.c"
    break;

  case 64: /* term: term MUL factor  */
#line 286 "bison/parser.y"
                      { (yyval.node) = new BinaryExpr("*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1844 "y.tab.c"
    break;

  case 65: /* term: term DIV factor  */
#line 287 "bison/parser.y"
                      { (yyval.node) = new BinaryExpr("/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1850 "y.tab.c"
    break;

  case 66: /* factor: NUM_INT  */
#line 291 "bison/parser.y"
                     { (yyval.node) = new NumberExpr((yyvsp[0].num)); }
#line 1856 "y.tab.c"
    break;

  case 67: /* factor: NUM_REAL  */
#line 292 "bison/parser.y"
                     { (yyval.node) = new NumberExpr((yyvsp[0].real)); }
#line 1862 "y.tab.c"
    break;

  case 68: /* factor: IDENTIFIER  */
#line 293 "bison/parser.y"
                     { (yyval.node) = new IdentifierExpr((yyvsp[0].id)); }
#line 1868 "y.tab.c"
    break;

  case 69: /* factor: STRING  */
#line 294 "bison/parser.y"
                     { (yyval.node) = new StringExpr(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1874 "y.tab.c"
    break;

  case 70: /* factor: BOOL_TRUE  */
#line 295 "bison/parser.y"
                     { (yyval.node) = new BoolExpr(true); }
#line 1880 "y.tab.c"
    break;

  case 71: /* factor: BOOL_FALSE  */
#line 296 "bison/parser.y"
                     { (yyval.node) = new BoolExpr(false); }
#line 1886 "y.tab.c"
    break;

  case 72: /* factor: func_call  */
#line 297 "bison/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1892 "y.tab.c"
    break;

  case 73: /* factor: LPAREN expr RPAREN  */
#line 298 "bison/parser.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 1898 "y.tab.c"
    break;

  case 74: /* func_call: IDENTIFIER LPAREN opt_args RPAREN  */
#line 302 "bison/parser.y"
                                      { (yyval.node) = new CallExpr(std::string((yyvsp[-3].id)), *(yyvsp[-1].stmts)); }
#line 1904 "y.tab.c"
    break;


#line 1908 "y.tab.c"

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

#line 305 "bison/parser.y"


void cleanup() {
    if (root) {
        delete root;
        root = nullptr;
    }
}
