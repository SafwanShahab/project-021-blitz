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
INVALID_ID {DIGIT}{LETTER}({LETTER}|{DIGIT})*

%%
"int"                           { printf("KEYWORD_INT\n"); col_num += yyleng; }
"num"                           { printf("KEYWORD_NUM\n"); col_num += yyleng; }
"if"                            { printf("KEYWORD_IF\n"); col_num += yyleng; }
"else"                          { printf("KEYWORD_ELSE\n"); col_num += yyleng; }
"while"                         { printf("KEYWORD_WHILE\n"); col_num += yyleng; }
"stop"                          { printf("KEYWORD_STOP\n"); col_num += yyleng; }
"read"                          { printf("KEYWORD_READ\n"); col_num += yyleng; }
"write"                         { printf("KEYWORD_WRITE\n"); col_num += yyleng; }
"+"                             { printf("OP_PLUS\n"); col_num += yyleng; }
"-"                             { printf("OP_MINUS\n"); col_num += yyleng; }
"*"                             { printf("OP_MULTIPLY\n"); col_num += yyleng; }
"/"                             { printf("OP_DIVIDE\n"); col_num += yyleng; }
":="                            { printf("OP_ASSIGN\n"); col_num += yyleng; }
"="                             { printf("OP_EQUAL\n"); col_num += yyleng; }
"=="                            { printf("OP_EQUAL_EQUAL\n"); col_num += yyleng; }
"!="                            { printf("OP_NOT_EQUAL\n"); col_num += yyleng; }
"<"                             { printf("OP_LESS_THAN\n"); col_num += yyleng; }
">"                             { printf("OP_GREATER_THAN\n"); col_num += yyleng; }
"<="                            { printf("OP_LESS_EQUAL\n"); col_num += yyleng; }
">="                            { printf("OP_GREATER_EQUAL\n"); col_num += yyleng; }
";"                             { printf("SEMICOLON\n"); col_num += yyleng; }
","                             { printf("COMMA\n"); col_num += yyleng; }
"("                             { printf("LPAREN\n"); col_num += yyleng; }
")"                             { printf("RPAREN\n"); col_num += yyleng; }
"{"                             { printf("LBRACE\n"); col_num += yyleng; }
"}"                             { printf("RBRACE\n"); col_num += yyleng; }
{ID}                            { printf("IDENTIFIER (%s)\n", yytext); col_num += yyleng; }
{NUM}                           { printf("NUMBER (%s)\n", yytext); col_num += yyleng; }
{INVALID_ID}                    { printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", line_num, col_num, yytext); exit(1); }
"//".*                          { /* Ignore comments */ }
"\\n"                           { line_num++; col_num = 1; }
[ \t\r]+                        { col_num += yyleng; /* Ignore whitespace */ }
.                               { printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", line_num, col_num, yytext); exit(1); }
%%
int yywrap() {
    return 1;
}
