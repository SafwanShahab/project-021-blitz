%{
#include <stdio.h>
#include <stdlib.h>

int line_num = 1;
int col_num = 1;

void yyerror(const char* s);
%}

DIGIT   [0-9]
LETTER  [a-zA-Z]
ID      {LETTER}({LETTER}|{DIGIT})*
NUM     {DIGIT}+

%%
"int"                           { printf("KEYWORD_INT\n"); }
"num"                           { printf("KEYWORD_NUM\n"); }
"if"                            { printf("KEYWORD_IF\n"); }
"else"                          { printf("KEYWORD_ELSE\n"); }
"while"                         { printf("KEYWORD_WHILE\n"); }
"stop"                          { printf("KEYWORD_STOP\n"); }
"read"                          { printf("KEYWORD_READ\n"); }
"write"                         { printf("KEYWORD_WRITE\n"); }
"+"                             { printf("OP_PLUS\n"); }
"-"                             { printf("OP_MINUS\n"); }
"*"                             { printf("OP_MULTIPLY\n"); }
"/"                             { printf("OP_DIVIDE\n"); }
"="                             { printf("OP_ASSIGN\n"); }
"=="                            { printf("OP_EQUAL\n"); }
"!="                            { printf("OP_NOT_EQUAL\n"); }
"<"                             { printf("OP_LESS_THAN\n"); }
">"                             { printf("OP_GREATER_THAN\n"); }
"<="                            { printf("OP_LESS_EQUAL\n"); }
">="                            { printf("OP_GREATER_EQUAL\n"); }
";"                             { printf("SEMICOLON\n"); }
","                             { printf("COMMA\n"); }
"("                             { printf("LPAREN\n"); }
")"                             { printf("RPAREN\n"); }
"{"                             { printf("LBRACE\n"); }
"}"                             { printf("RBRACE\n"); }
{ID}                            { printf("IDENTIFIER (%s)\n", yytext); }
{NUM}                           { printf("NUMBER (%s)\n", yytext); }
"//".*                          { /* Ignore comments */ }
"\\n"                           { line_num++; col_num = 1; }
[ \t\r]+                        { /* Ignore whitespace */ }
.                               { yyerror("unrecognized symbol"); }
%%

void yyerror(const char* s) {
    fprintf(stderr, "Error at line %d, column %d: %s\n", line_num, col_num, s);
    exit(1);
}

int main(int argc, char **argv) {
    ++argv, --argc;  /* skip over program name */
    if (argc > 0)
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;

    yylex();
    return 0;
}
