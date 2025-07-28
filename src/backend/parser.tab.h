/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    #include "ast/NumberExpr.hpp"
    #include "ast/VarDecl.hpp"
    #include "ast/Program.hpp"
    #include "ast/AssignStmt.hpp"
    #include "ast/Block.hpp"
    #include "ast/IfStmt.hpp"
    #include "ast/WhileStmt.hpp"
    #include "ast/ReturnStmt.hpp"
    #include <vector>
    #include <string>

#line 68 "parser.tab.h"

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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "bison/parser.y"

    int num;
    float real;
    bool bval;
    char* id;
    ASTNode* node;
    std::string* str;
    std::vector<ASTNode*>* stmts;

#line 139 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
