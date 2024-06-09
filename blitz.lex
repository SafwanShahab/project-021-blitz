%{
#include "blitz.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the global variables as extern
extern int brace_count;
extern int paren_count;

int line_num = 1;
int col_num = 1;
%}

DIGIT   [0-9]
LETTER  [a-zA-Z]
ID      {LETTER}({LETTER}|{DIGIT})*
NUM     {DIGIT}+

%%
"void"                          { col_num += yyleng; printf("KEYWORD_VOID\n"); }
"int"                           { col_num += yyleng; printf("KEYWORD_INT\n"); }
"num"                           { col_num += yyleng; printf("KEYWORD_NUM\n"); }
"if"                            { col_num += yyleng; printf("KEYWORD_IF\n"); }
"else"                          { col_num += yyleng; printf("KEYWORD_ELSE\n"); }
"while"                         { col_num += yyleng; printf("KEYWORD_WHILE\n"); }
"stop"                          { col_num += yyleng; printf("KEYWORD_STOP\n"); }
"read"                          { col_num += yyleng; printf("KEYWORD_READ\n"); }
"write"                         { col_num += yyleng; printf("KEYWORD_WRITE\n"); }
"+"                             { col_num += yyleng; printf("OP_PLUS\n"); }
"-"                             { col_num += yyleng; printf("OP_MINUS\n"); }
"*"                             { col_num += yyleng; printf("OP_MULTIPLY\n"); }
"/"                             { col_num += yyleng; printf("OP_DIVIDE\n"); }
":="                            { col_num += yyleng; printf("OP_ASSIGN\n"); }
"="                             { col_num += yyleng; printf("OP_EQUAL\n"); }
"=="                            { col_num += yyleng; printf("OP_EQUAL_EQUAL\n"); }
"!="                            { col_num += yyleng; printf("OP_NOT_EQUAL\n"); }
"<"                             { col_num += yyleng; printf("OP_LESS_THAN\n"); }
">"                             { col_num += yyleng; printf("OP_GREATER_THAN\n"); }
"<="                            { col_num += yyleng; printf("OP_LESS_EQUAL\n"); }
">="                            { col_num += yyleng; printf("OP_GREATER_EQUAL\n"); }
";"                             { col_num += yyleng; printf("SEMICOLON\n"); }
","                             { col_num += yyleng; printf("COMMA\n"); }
"("                             { col_num += yyleng; printf("LPAREN\n"); paren_count++; }
")"                             { col_num += yyleng; printf("RPAREN\n"); paren_count--; }
"{"                             { col_num += yyleng; printf("LBRACE\n"); brace_count++; }
"}"                             { col_num += yyleng; printf("RBRACE\n"); brace_count--; }
{ID}                            { col_num += yyleng; printf("IDENTIFIER (%s)\n", yytext); }
{NUM}                           { col_num += yyleng; printf("NUMBER (%s)\n", yytext); }
"//".*                          { col_num += yyleng; /* Ignore comments */ }
"\n"                            { line_num++; col_num = 1; }
[ \t\r]+                        { col_num += yyleng; /* Ignore whitespace */ }
.                               { printf("Error: unrecognized symbol \"%s\" at line %d, column %d\n", yytext, line_num, col_num); col_num += yyleng; exit(1); }
%%
int yywrap() {
    return 1;
}
