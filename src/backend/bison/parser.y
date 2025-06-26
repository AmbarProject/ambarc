%{
#include <iostream>
#include <string>

extern int yylex();
void yyerror(const char *s);

typedef union {
    char* id;
    int num;
    float real;
} YYSTYPE;

extern YYSTYPE yylval;
%}

%token <id> IDENTIFICADOR
%token <num> NUM_INT
%token <real> NUM_REAL
%token STRING
%token BOOL_TRUE BOOL_FALSE

%token IMPORT FUNC RETURN IF ELSE WHILE FOR BREAK CONTINUE
%token INT FLOAT BOOL STRING_T VOID
%token AND OR EQ NEQ LT LE GT GE
%token ADD SUB MUL DIV ASSIGN ARROW
%token SEMI COLON COMMA DOT LPAREN RPAREN LBRACE RBRACE

%start programa

%%

programa: lista_declaracoes;

lista_declaracoes: 
    | lista_declaracoes declaracao;

declaracao: 
    declaracao_import
    | declaracao_variavel
    | declaracao_funcao
    | instrucao;

declaracao_import: 
    IMPORT IDENTIFICADOR ARROW IDENTIFICADOR SEMI;

declaracao_variavel: 
    IDENTIFICADOR COLON tipo ASSIGN expressao SEMI
    | IDENTIFICADOR COLON tipo SEMI;

declaracao_funcao: 
    FUNC IDENTIFICADOR LPAREN parametros_opt RPAREN ARROW tipo bloco_codigo;

parametros_opt: 
    | parametros;

parametros: 
    tipo IDENTIFICADOR
    | parametros COMMA tipo IDENTIFICADOR;

instrucao: 
    instrucao_atribuicao
    | instrucao_chamada
    | instrucao_retorno
    | instrucao_if
    | instrucao_while
    | instrucao_for
    | instrucao_break
    | instrucao_continue
    | bloco_codigo;

instrucao_atribuicao: 
    IDENTIFICADOR ASSIGN expressao SEMI;

instrucao_chamada: 
    IDENTIFICADOR LPAREN argumentos_opt RPAREN SEMI;

instrucao_retorno: 
    RETURN expressao SEMI
    | RETURN SEMI;

instrucao_if: 
    IF LPAREN expressao RPAREN bloco_codigo
    | IF LPAREN expressao RPAREN bloco_codigo ELSE bloco_codigo;

instrucao_while: 
    WHILE LPAREN expressao RPAREN bloco_codigo;

instrucao_for: 
    FOR LPAREN instrucao_atribuicao expressao SEMI instrucao_atribuicao RPAREN bloco_codigo;

instrucao_break: 
    BREAK SEMI;

instrucao_continue: 
    CONTINUE SEMI;

bloco_codigo: 
    LBRACE lista_instrucao RBRACE;

lista_instrucao: 
    | lista_instrucao instrucao;

argumentos_opt: 
    | argumentos;

argumentos: 
    expressao
    | argumentos COMMA expressao;

expressao: 
    expressao_logica;

expressao_logica: 
    expressao_relacional
    | expressao_logica AND expressao_relacional
    | expressao_logica OR expressao_relacional;

expressao_relacional: 
    expressao_aritmetica
    | expressao_aritmetica EQ expressao_aritmetica
    | expressao_aritmetica NEQ expressao_aritmetica
    | expressao_aritmetica LT expressao_aritmetica
    | expressao_aritmetica LE expressao_aritmetica
    | expressao_aritmetica GT expressao_aritmetica
    | expressao_aritmetica GE expressao_aritmetica;

expressao_aritmetica: 
    termo
    | expressao_aritmetica ADD termo
    | expressao_aritmetica SUB termo;

termo: 
    fator
    | termo MUL fator
    | termo DIV fator;

fator: 
    NUM_INT
    | NUM_REAL
    | IDENTIFICADOR
    | chamada_funcao
    | LPAREN expressao RPAREN;

chamada_funcao: 
    IDENTIFICADOR LPAREN argumentos_opt RPAREN;

expressao_membro: 
    IDENTIFICADOR
    | expressao_membro DOT IDENTIFICADOR;

tipo: 
    INT
    | FLOAT
    | BOOL
    | STRING_T
    | VOID;

%%

void yyerror(const char *s) {
    std::cerr << "Erro de sintaxe: " << s << std::endl;
}