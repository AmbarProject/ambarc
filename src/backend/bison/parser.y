%code requires {
    #include "ast/AST.hpp"
    #include "ast/BinaryExpr.hpp"
    #include "ast/NumberExpr.hpp"
    #include "ast/VarDecl.hpp"
    #include "ast/Program.hpp"
    #include "ast/AssignStmt.hpp"
}

%{
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
%}

%union {
    char* id;
    int num;
    float real;
    ASTNode* node;
    std::string* str;
}

%type <node> 
    program 
    decl_list 
    decl 
    var_decl 
    stmt 
    assign_stmt 
    call_stmt 
    return_stmt 
    if_stmt 
    while_stmt 
    for_stmt 
    break_stmt 
    continue_stmt 
    block 
    expr 
    logic_expr 
    rel_expr 
    arith_expr 
    term 
    factor 
    func_call

%type <str> type

%token <id> IDENTIFIER
%token <num> NUM_INT
%token <real> NUM_REAL
%token <id> STRING
%token BOOL_TRUE BOOL_FALSE

%token IMPORT FUNC RETURN IF ELSE WHILE FOR BREAK CONTINUE
%token INT FLOAT BOOL STRING_T VOID
%token AND OR EQ NEQ LT LE GT GE
%token ADD SUB MUL DIV ASSIGN ARROW
%token SEMI COLON COMMA DOT LPAREN RPAREN LBRACE RBRACE

%start program

%%

program:
    decl_list {
        Program* prog = dynamic_cast<Program*>($1);
        if (!prog) {
            prog = new Program();
            prog->add($1);
        }
        root = prog;
    }
;


decl_list:
      decl {
          Program* p = new Program();
          p->add($1);
          $$ = p;
      }
    | decl_list decl {
          Program* p = dynamic_cast<Program*>($1);
          p->add($2);
          $$ = p;
      }
;



decl: 
      import_decl         { $$ = nullptr; }
    | var_decl            { $$ = $1; }
    | func_decl           { $$ = nullptr; }
    | stmt                { $$ = $1; }
    ;

import_decl: 
    IMPORT IDENTIFIER ARROW IDENTIFIER SEMI
    ;

var_decl: 
    IDENTIFIER COLON type ASSIGN expr SEMI { $$ = new VarDecl($1, *$3, $5); }
    | IDENTIFIER COLON type SEMI { $$ = new VarDecl($1, *$3, nullptr); }
  ;

func_decl: 
    FUNC IDENTIFIER LPAREN opt_params RPAREN ARROW type block
    ;

opt_params: 
    /* empty */
    | params
    ;

params: 
    type IDENTIFIER
    | params COMMA type IDENTIFIER
    ;

type: 
    INT         { $$ = new std::string("int"); }
    | FLOAT     { $$ = new std::string("float"); }  
    | BOOL      { $$ = new std::string("bool"); }
    | STRING_T  { $$ = new std::string("string"); }
    | VOID      { $$ = new std::string("void"); }
    ;

stmt: 
      assign_stmt      { $$ = $1; }
    | call_stmt        { $$ = nullptr; }
    | return_stmt      { $$ = nullptr; }
    | if_stmt          { $$ = nullptr; }
    | while_stmt       { $$ = nullptr; }
    | for_stmt         { $$ = nullptr; }
    | break_stmt       { $$ = nullptr; }
    | continue_stmt    { $$ = nullptr; }
    | block            { $$ = nullptr; }
    ;

assign_stmt: 
    IDENTIFIER ASSIGN expr SEMI { $$ = new AssignStmt($1, $3); }
    ;

call_stmt: 
    IDENTIFIER LPAREN opt_args RPAREN SEMI
    ;

return_stmt: 
    RETURN expr SEMI
    | RETURN SEMI
    ;

if_stmt: 
    IF LPAREN expr RPAREN block
    | IF LPAREN expr RPAREN block ELSE block
    ;

while_stmt: 
    WHILE LPAREN expr RPAREN block
    ;

for_stmt: 
    FOR LPAREN assign_stmt expr SEMI assign_stmt RPAREN block
    ;

break_stmt: 
    BREAK SEMI
    ;

continue_stmt: 
    CONTINUE SEMI
    ;

block: 
    LBRACE stmt_list RBRACE
    ;

stmt_list: 
    /* empty */
    | stmt_list stmt
    ;

opt_args: 
    /* empty */
    | args
    ;

args: 
    expr
    | args COMMA expr
    ;

expr: 
    logic_expr { $$ = $1; }
    ;

logic_expr: 
      rel_expr { $$ = $1; }
    | logic_expr AND rel_expr { $$ = new BinaryExpr("AND", $1, $3); }
    | logic_expr OR rel_expr { $$ = new BinaryExpr("OR", $1, $3); }
    ;

rel_expr: 
      arith_expr { $$ = $1; }
    | arith_expr EQ arith_expr { $$ = new BinaryExpr("==", $1, $3); }
    | arith_expr NEQ arith_expr { $$ = new BinaryExpr("!=", $1, $3); }
    | arith_expr LT arith_expr { $$ = new BinaryExpr("<", $1, $3); }
    | arith_expr LE arith_expr { $$ = new BinaryExpr("<=", $1, $3); }
    | arith_expr GT arith_expr { $$ = new BinaryExpr(">", $1, $3); }
    | arith_expr GE arith_expr { $$ = new BinaryExpr(">=", $1, $3); }
    ;

arith_expr: 
      term { $$ = $1; }
    | arith_expr ADD term { $$ = new BinaryExpr("+", $1, $3); }
    | arith_expr SUB term { $$ = new BinaryExpr("-", $1, $3); }
    ;

term: 
      factor { $$ = $1; }
    | term MUL factor { $$ = new BinaryExpr("*", $1, $3); }
    | term DIV factor { $$ = new BinaryExpr("/", $1, $3); }
    ;

factor: 
      NUM_INT { $$ = new NumberExpr($1); }
    | NUM_REAL { $$ = new NumberExpr($1); }
    | IDENTIFIER { $$ = nullptr; }
    | STRING { $$ = nullptr; }
    | BOOL_TRUE { $$ = nullptr; }
    | BOOL_FALSE { $$ = nullptr; }
    | LPAREN expr RPAREN { $$ = $2; }
    ;

func_call: 
    IDENTIFIER LPAREN opt_args RPAREN { $$ = nullptr; }
    ;

%%

void yyerror(const char *s) {
    std::cerr << "Syntax error: " << s << std::endl;
}