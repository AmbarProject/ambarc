%code requires {
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
%}

%union {
    int num;
    float real;
    bool bval;
    char* id;
    ASTNode* node;
    std::string* str;
    std::vector<ASTNode*>* stmts;
    std::vector<std::pair<std::string, std::string>>* params;
}

%type <node> program decl_list decl var_decl stmt assign_stmt call_stmt 
             return_stmt if_stmt while_stmt for_stmt break_stmt continue_stmt 
             block expr logic_expr rel_expr arith_expr term factor func_call
             func_decl import_decl

%type <str> type
%type <stmts> stmt_list
%type <params> params opt_params
%type <stmts> opt_args args

%token <id> IDENTIFIER
%token <num> NUM_INT
%token <real> NUM_REAL
%token <str> STRING
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
    | func_decl           { $$ = $1; }
    | stmt                { $$ = $1; }
;

import_decl: 
    IMPORT IDENTIFIER ARROW IDENTIFIER SEMI { $$ = nullptr; }
;

var_decl:
      IDENTIFIER COLON type ASSIGN expr SEMI { 
          $$ = new VarDecl(std::string($1), *$3, $5); 
          delete $3;
      }
    | IDENTIFIER COLON type SEMI { 
          $$ = new VarDecl(std::string($1), *$3, nullptr);
          delete $3;
      }
;

func_decl: 
    FUNC IDENTIFIER LPAREN opt_params RPAREN ARROW type block {
        $$ = new FunctionDecl(std::string($2), *$7, 
                             ($4 != nullptr) ? *$4 : std::vector<std::pair<std::string, std::string>>(),
                             dynamic_cast<Block*>($8));
        delete $4; 
        delete $7; 
        }
;

opt_params: 
      { $$ = nullptr; }  
    | params { $$ = $1; } 
;

params: 
      IDENTIFIER COLON type {
          $$ = new std::vector<std::pair<std::string, std::string>>();
          $$->push_back({std::string($1), *$3});
          delete $3; 
      }
    | params COMMA IDENTIFIER COLON type {
          $1->push_back({std::string($3), *$5});
          delete $5; 
          $$ = $1;
      }
;

type:
    INT       { $$ = new std::string("int"); }
  | FLOAT     { $$ = new std::string("float"); }
  | BOOL      { $$ = new std::string("bool"); }
  | STRING_T  { $$ = new std::string("string"); }
  | VOID      { $$ = new std::string("void"); }
;

stmt: 
      assign_stmt      { $$ = $1; }
    | call_stmt        { $$ = $1; }
    | return_stmt      { $$ = $1; }
    | if_stmt          { $$ = $1; }
    | while_stmt       { $$ = $1; }
    | for_stmt         { $$ = $1; }
    | break_stmt       { $$ = $1; }
    | continue_stmt    { $$ = $1; }
    | block            { $$ = $1; }
;

assign_stmt: 
    IDENTIFIER ASSIGN expr SEMI { $$ = new AssignStmt($1, $3); }
;

call_stmt: 
    func_call SEMI { $$ = $1; }
;

return_stmt: 
      RETURN expr SEMI { $$ = new ReturnStmt($2); }
    | RETURN SEMI { $$ = new ReturnStmt(); }
;

if_stmt: 
      IF LPAREN expr RPAREN block {
          $$ = new IfStmt($3, $5);
      }
    | IF LPAREN expr RPAREN block ELSE block {
          $$ = new IfStmt($3, $5, $7);
      }
;

while_stmt:
    WHILE LPAREN expr RPAREN block {
        $$ = new WhileStmt($3, $5);
    }
;

for_stmt: 
    FOR LPAREN assign_stmt expr SEMI assign_stmt RPAREN block {
        $$ = new ForStmt($3, $4, $6, dynamic_cast<Block*>($8));
    }
;

break_stmt: 
    BREAK SEMI { $$ = new BreakStmt(); }
;

continue_stmt: 
    CONTINUE SEMI { $$ = new ContinueStmt(); }
;

block:
    LBRACE RBRACE {
        $$ = new Block();
    }
    | LBRACE stmt_list RBRACE {
        Block* blk = new Block();
        if ($2) {
            for (ASTNode* stmt : *$2) {
                blk->add(stmt);
            }
            delete $2;
        }
        $$ = blk;
    }
;

stmt_list:
      stmt {
        $$ = new std::vector<ASTNode*>();
        if ($1) $$->push_back($1);
      }
    | stmt_list stmt {
        if ($2) $1->push_back($2);
        $$ = $1;
      }
;

opt_args: 
      { $$ = new std::vector<ASTNode*>(); }
    | args { $$ = $1; }
;

args: 
      expr { $$ = new std::vector<ASTNode*>(); $$->push_back($1); }
    | args COMMA expr { $1->push_back($3); $$ = $1; }
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
      NUM_INT        { $$ = new NumberExpr($1); }
    | NUM_REAL       { $$ = new NumberExpr($1); }
    | IDENTIFIER     { $$ = new IdentifierExpr($1); }
    | STRING         { $$ = new StringExpr(*$1); delete $1; }
    | BOOL_TRUE      { $$ = new BoolExpr(true); }
    | BOOL_FALSE     { $$ = new BoolExpr(false); }
    | func_call      { $$ = $1; }
    | LPAREN expr RPAREN { $$ = $2; }
;

func_call: 
    IDENTIFIER LPAREN opt_args RPAREN { $$ = new CallExpr(std::string($1), *$3); }
;

%%

void cleanup() {
    if (root) {
        delete root;
        root = nullptr;
    }
}