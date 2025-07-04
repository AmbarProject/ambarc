%code requires {
    #include "AST.hpp"
    #include "BinaryExpr.hpp"
    #include "NumberExpr.hpp"
    #include "VarDecl.hpp"
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
    programa 
    lista_declaracoes 
    declaracao 
    declaracao_variavel 
    instrucao 
    instrucao_atribuicao 
    instrucao_chamada 
    instrucao_retorno 
    instrucao_if 
    instrucao_while 
    instrucao_for 
    instrucao_break 
    instrucao_continue 
    bloco_codigo 
    expressao 
    expressao_logica 
    expressao_relacional 
    expressao_aritmetica 
    termo 
    fator 
    chamada_funcao

%type <str> tipo

%token <id> IDENTIFICADOR
%token <num> NUM_INT
%token <real> NUM_REAL
%token <id> STRING
%token BOOL_TRUE BOOL_FALSE

%token IMPORT FUNC RETURN IF ELSE WHILE FOR BREAK CONTINUE
%token INT FLOAT BOOL STRING_T VOID
%token AND OR EQ NEQ LT LE GT GE
%token ADD SUB MUL DIV ASSIGN ARROW
%token SEMI COLON COMMA DOT LPAREN RPAREN LBRACE RBRACE

%start programa

%%

programa: 
    lista_declaracoes { root = $1; }
    ;

lista_declaracoes: 
      declaracao { $$ = $1; }
    | lista_declaracoes declaracao { $$ = $2 ? $2 : $1; }
    ;

declaracao: 
      declaracao_import         { $$ = nullptr; }
    | declaracao_variavel       { $$ = $1; }
    | declaracao_funcao         { $$ = nullptr; }
    | instrucao                 { $$ = $1; }
    ;

declaracao_import: 
    IMPORT IDENTIFICADOR ARROW IDENTIFICADOR SEMI
    ;

declaracao_variavel: 
    IDENTIFICADOR COLON tipo ASSIGN expressao SEMI { $$ = new VarDecl($1, *$3, $5); }
    | IDENTIFICADOR COLON tipo SEMI { $$ = new VarDecl($1, *$3, nullptr); }
  ;

declaracao_funcao: 
    FUNC IDENTIFICADOR LPAREN parametros_opt RPAREN ARROW tipo bloco_codigo
    ;

parametros_opt: 
    /* vazio */
    | parametros
    ;

parametros: 
    tipo IDENTIFICADOR
    | parametros COMMA tipo IDENTIFICADOR
    ;

tipo: 
    INT         { $$ = new std::string("int"); }
    | FLOAT     { $$ = new std::string("float"); }  
    | BOOL      { $$ = new std::string("bool"); }
    | STRING_T  {$$ = new std::string("string"); }
    | VOID      { $$ = new std::string("void"); }
    ;

instrucao: 
      instrucao_atribuicao      { $$ = nullptr; }
    | instrucao_chamada         { $$ = nullptr; }
    | instrucao_retorno         { $$ = nullptr; }
    | instrucao_if              { $$ = nullptr; }
    | instrucao_while           { $$ = nullptr; }
    | instrucao_for             { $$ = nullptr; }
    | instrucao_break           { $$ = nullptr; }
    | instrucao_continue        { $$ = nullptr; }
    | bloco_codigo              { $$ = nullptr; }
    ;

instrucao_atribuicao: 
    IDENTIFICADOR ASSIGN expressao SEMI
    ;

instrucao_chamada: 
    IDENTIFICADOR LPAREN argumentos_opt RPAREN SEMI
    ;

instrucao_retorno: 
    RETURN expressao SEMI
    | RETURN SEMI
    ;

instrucao_if: 
    IF LPAREN expressao RPAREN bloco_codigo
    | IF LPAREN expressao RPAREN bloco_codigo ELSE bloco_codigo
    ;

instrucao_while: 
    WHILE LPAREN expressao RPAREN bloco_codigo
    ;

instrucao_for: 
    FOR LPAREN instrucao_atribuicao expressao SEMI instrucao_atribuicao RPAREN bloco_codigo
    ;

instrucao_break: 
    BREAK SEMI
    ;

instrucao_continue: 
    CONTINUE SEMI
    ;

bloco_codigo: 
    LBRACE lista_instrucao RBRACE
    ;

lista_instrucao: 
    /* vazio */
    | lista_instrucao instrucao
    ;

argumentos_opt: 
    /* vazio */
    | argumentos
    ;

argumentos: 
    expressao
    | argumentos COMMA expressao
    ;

expressao: 
    expressao_logica { $$ = $1; }
    ;

expressao_logica: 
      expressao_relacional { $$ = $1; }
    | expressao_logica AND expressao_relacional { $$ = new BinaryExpr("AND", $1, $3); }
    | expressao_logica OR expressao_relacional { $$ = new BinaryExpr("OR", $1, $3); }
    ;

expressao_relacional: 
      expressao_aritmetica { $$ = $1; }
    | expressao_aritmetica EQ expressao_aritmetica { $$ = new BinaryExpr("==", $1, $3); }
    | expressao_aritmetica NEQ expressao_aritmetica { $$ = new BinaryExpr("!=", $1, $3); }
    | expressao_aritmetica LT expressao_aritmetica { $$ = new BinaryExpr("<", $1, $3); }
    | expressao_aritmetica LE expressao_aritmetica { $$ = new BinaryExpr("<=", $1, $3); }
    | expressao_aritmetica GT expressao_aritmetica { $$ = new BinaryExpr(">", $1, $3); }
    | expressao_aritmetica GE expressao_aritmetica { $$ = new BinaryExpr(">=", $1, $3); }
    ;

expressao_aritmetica: 
      termo { $$ = $1; }
    | expressao_aritmetica ADD termo { $$ = new BinaryExpr("+", $1, $3); }
    | expressao_aritmetica SUB termo { $$ = new BinaryExpr("-", $1, $3); }
    ;

termo: 
      fator { $$ = $1; }
    | termo MUL fator { $$ = new BinaryExpr("*", $1, $3); }
    | termo DIV fator { $$ = new BinaryExpr("/", $1, $3); }
    ;

fator: 
      NUM_INT { $$ = new NumberExpr($1); }
    | NUM_REAL { $$ = new NumberExpr($1); }
    | IDENTIFICADOR { $$ = nullptr; }
    | STRING { $$ = nullptr; }
    | BOOL_TRUE { $$ = nullptr; }
    | BOOL_FALSE { $$ = nullptr; }
    | LPAREN expressao RPAREN { $$ = $2; }
    ;

chamada_funcao: 
    IDENTIFICADOR LPAREN argumentos_opt RPAREN { $$ = nullptr; }
    ;

%%

void yyerror(const char *s) {
    std::cerr << "Erro de sintaxe: " << s << std::endl;
}
