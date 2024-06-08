%{
#include "blitz.tab.h"
#include <stdio.h>

int line_num = 1;
int col_num = 1;
%}

DIGIT   [0-9]
LETTER  [a-zA-Z]
ID      {LETTER}({LETTER}|{DIGIT})*
NUM     {DIGIT}+

%%

"int"                           { col_num += yyleng; printf("Token: int\n"); return KEYWORD_INT; }
"num"                           { col_num += yyleng; printf("Token: num\n"); return KEYWORD_NUM; }
"if"                            { col_num += yyleng; printf("Token: if\n"); return KEYWORD_IF; }
"else"                          { col_num += yyleng; printf("Token: else\n"); return KEYWORD_ELSE; }
"while"                         { col_num += yyleng; printf("Token: while\n"); return KEYWORD_WHILE; }
"stop"                          { col_num += yyleng; printf("Token: stop\n"); return KEYWORD_STOP; }
"read"                          { col_num += yyleng; printf("Token: read\n"); return KEYWORD_READ; }
"write"                         { col_num += yyleng; printf("Token: write\n"); return KEYWORD_WRITE; }
"+"                             { col_num += yyleng; printf("Token: +\n"); return OP_PLUS; }
"-"                             { col_num += yyleng; printf("Token: -\n"); return OP_MINUS; }
"*"                             { col_num += yyleng; printf("Token: *\n"); return OP_MULTIPLY; }
"/"                             { col_num += yyleng; printf("Token: /\n"); return OP_DIVIDE; }
":="                            { col_num += yyleng; printf("Token: :=\n"); return OP_ASSIGN; }
"="                             { col_num += yyleng; printf("Token: =\n"); return OP_EQUAL; }
"=="                            { col_num += yyleng; printf("Token: ==\n"); return OP_EQUAL_EQUAL; }
"!="                            { col_num += yyleng; printf("Token: !=\n"); return OP_NOT_EQUAL; }
"<"                             { col_num += yyleng; printf("Token: <\n"); return OP_LESS_THAN; }
">"                             { col_num += yyleng; printf("Token: >\n"); return OP_GREATER_THAN; }
"<="                            { col_num += yyleng; printf("Token: <=\n"); return OP_LESS_EQUAL; }
">="                            { col_num += yyleng; printf("Token: >=\n"); return OP_GREATER_EQUAL; }
";"                             { col_num += yyleng; printf("Token: ;\n"); return SEMICOLON; }
","                             { col_num += yyleng; printf("Token: ,\n"); return COMMA; }
"("                             { col_num += yyleng; printf("Token: (\n"); return LPAREN; }
")"                             { col_num += yyleng; printf("Token: )\n"); return RPAREN; }
"{"                             { col_num += yyleng; printf("Token: {\n"); return LBRACE; }
"}"                             { col_num += yyleng; printf("Token: }\n"); return RBRACE; }
{ID}                            { col_num += yyleng; printf("Token: identifier (%s)\n", yytext); yylval.str = strdup(yytext); return IDENTIFIER; }
{NUM}                           { col_num += yyleng; printf("Token: number (%s)\n", yytext); yylval.num = atoi(yytext); return NUMBER; }
"//".*                          { /* Ignore comments */ }
"\\n"                           { line_num++; col_num = 1; }
[ \t\r]+                        { col_num += yyleng; /* Ignore whitespace */ }
[0-9]+{LETTER}+                 { 
                                  fprintf(stderr, "Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", line_num, col_num, yytext); 
                                  exit(1); 
                                }
.                               { 
                                  fprintf(stderr, "Error at line %d, column %d: unrecognized symbol \"%s\"\n", line_num, col_num, yytext); 
                                  exit(1); 
                                }
%%

int yywrap() {
    return 1;
}