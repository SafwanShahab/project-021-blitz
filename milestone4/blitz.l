%{
#include "blitz.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_num = 1;
int col_num = 1;
%}

DIGIT   [0-9]
LETTER  [a-zA-Z]
ID      {LETTER}({LETTER}|{DIGIT})*
NUM     {DIGIT}+

%%
"void"                          { col_num += yyleng; return KEYWORD_FUNC; }
"int"                           { col_num += yyleng; return KEYWORD_INT; }
"num"                           { col_num += yyleng; return KEYWORD_NUM; }
"if"                            { col_num += yyleng; return KEYWORD_IF; }
"else"                          { col_num += yyleng; return KEYWORD_ELSE; }
"while"                         { col_num += yyleng; return KEYWORD_WHILE; }
"stop"                          { col_num += yyleng; return KEYWORD_STOP; }
"read"                          { col_num += yyleng; return KEYWORD_READ; }
"write"                         { col_num += yyleng; return KEYWORD_WRITE; }
"for"                           { col_num += yyleng; return KEYWORD_FOR; }
"return"                        { col_num += yyleng; return KEYWORD_RETURN; }
"+"                             { col_num += yyleng; return OP_PLUS; }
"-"                             { col_num += yyleng; return OP_MINUS; }
"*"                             { col_num += yyleng; return OP_MULTIPLY; }
"/"                             { col_num += yyleng; return OP_DIVIDE; }
":="                            { col_num += yyleng; return OP_ASSIGN; }
"="                             { col_num += yyleng; return OP_EQUAL; }
"=="                            { col_num += yyleng; return OP_EQUAL_EQUAL; }
"!="                            { col_num += yyleng; return OP_NOT_EQUAL; }
"<"                             { col_num += yyleng; return OP_LESS_THAN; }
">"                             { col_num += yyleng; return OP_GREATER_THAN; }
"<="                            { col_num += yyleng; return OP_LESS_EQUAL; }
">="                            { col_num += yyleng; return OP_GREATER_EQUAL; }
";"                             { col_num += yyleng; return SEMICOLON; }
","                             { col_num += yyleng; return COMMA; }
"("                             { col_num += yyleng; return LPAREN; }
")"                             { col_num += yyleng; return RPAREN; }
"{"                             { col_num += yyleng; return LBRACE; }
"}"                             { col_num += yyleng; return RBRACE; }
"["                             { col_num += yyleng; return LBRACKET; }
"]"                             { col_num += yyleng; return RBRACKET; }
{ID}                            { col_num += yyleng; yylval.str = strdup(yytext); return IDENTIFIER; }
{NUM}                           { col_num += yyleng; yylval.num = atoi(yytext); return NUMBER; }
"//".*                          { /* Ignore comments */ }
"\n"                            { line_num++; col_num = 1; }
[ \t\r]+                        { col_num += yyleng; /* Ignore whitespace */ }
.                               { printf("Error: unrecognized symbol \"%s\" at line %d, column %d\n", yytext, line_num, col_num); col_num += yyleng; exit(1); }
%%
int yywrap() {
    return 1;
}
