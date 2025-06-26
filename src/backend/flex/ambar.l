%option noyywrap

%{
#include "parser.tab.h"
#include <string.h>
#include <stdlib.h>

extern YYSTYPE yylval;
void yyerror(const char *s);
%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
NUM_INT     [0-9]+
NUM_REAL    [0-9]+"."[0-9]+
ID          [a-zA-Z_][a-zA-Z0-9_]*
ESPACO      [ \t\r\n]+

%%

"import"        { return IMPORT; }
"func"          { return FUNC; }
"return"        { return RETURN; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }

"int"           { return INT; }
"float"         { return FLOAT; }
"bool"          { return BOOL; }
"string"        { return STRING_T; }
"void"          { return VOID; }

"true"          { return BOOL_TRUE; }
"false"         { return BOOL_FALSE; }

"&&"            { return AND; }
"||"            { return OR; }
"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LE; }
">="            { return GE; }
"<"             { return LT; }
">"             { return GT; }
"+"             { return ADD; }
"-"             { return SUB; }
"*"             { return MUL; }
"/"             { return DIV; }
"="             { return ASSIGN; }
"->"            { return ARROW; }

";"             { return SEMI; }
":"             { return COLON; }
","             { return COMMA; }
"."             { return DOT; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

{NUM_REAL}      { yylval.real = atof(yytext); return NUM_REAL; }
{NUM_INT}       { yylval.num = atoi(yytext); return NUM_INT; }
{ID}            { yylval.id = strdup(yytext); return IDENTIFICADOR; }
\"([^\"\\]|\\.)*\"  { yylval.id = strdup(yytext); return STRING; }

"//".*          { }
"/*"([^*]|\*+[^*/])*\*+"/" { }
{ESPACO}        { }

.               { printf("Caractere inesperado: %s\n", yytext); }

%%