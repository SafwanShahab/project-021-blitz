%{
#include "mil.h"
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

"int"                           { col_num += yyleng; return KEYWORD_INT; }
"num"                           { col_num += yyleng; return KEYWORD_NUM; }
"if"                            { col_num += yyleng; return KEYWORD_IF; }
"else"                          { col_num += yyleng; return KEYWORD_ELSE; }
"while"                         { col_num += yyleng; return KEYWORD_WHILE; }
"stop"                          { col_num += yyleng; return KEYWORD_STOP; }
"read"                          { col_num += yyleng; return KEYWORD_READ; }
"write"                         { col_num += yyleng; return KEYWORD_WRITE; }
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
{ID}                            { col_num += yyleng; yylval.str = strdup(yytext); return IDENTIFIER; }
{NUM}                           { col_num += yyleng; yylval.num = atoi(yytext); return NUMBER_CONST; }
"//".*                          { /* Ignore comments */ }
"\n"                            { line_num++; col_num = 1; }
[ \t\r]+                        { col_num += yyleng; /* Ignore whitespace */ }
.                               { 
                                  fprintf(stderr, "Error at line %d, column %d: unrecognized symbol \"%s\"\n", line_num, col_num, yytext); 
                                  exit(1); 
                                }
%%

int yywrap() {
    return 1;
}
