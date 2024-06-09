%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "mil.h"

void yyerror(const char* s);
int yylex(void);

extern FILE* yyin;
extern int yylineno;
extern char* yytext;

%}

%union {
    int num;
    char* str;
}

%token <num> NUMBER_CONST
%token <str> IDENTIFIER
%token KEYWORD_INT KEYWORD_NUM KEYWORD_IF KEYWORD_ELSE KEYWORD_WHILE KEYWORD_STOP KEYWORD_READ KEYWORD_WRITE
%token OP_ASSIGN OP_EQUAL OP_EQUAL_EQUAL OP_NOT_EQUAL OP_LESS_THAN OP_GREATER_THAN OP_LESS_EQUAL OP_GREATER_EQUAL
%token OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVIDE
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE

%type <str> assignment if_statement while_statement write_statement expression condition
%type <str> declaration read_statement stop_statement
%type <str> statement statement_list

%right OP_ASSIGN
%left OP_PLUS OP_MINUS
%left OP_MULTIPLY OP_DIVIDE
%nonassoc OP_EQUAL OP_NOT_EQUAL OP_LESS_THAN OP_GREATER_THAN OP_LESS_EQUAL OP_GREATER_EQUAL

%%

program:
    program statement
    | /* empty */
    ;

statement:
    declaration
    | assignment
    | if_statement
    | while_statement
    | read_statement
    | write_statement
    | stop_statement
    ;

declaration:
    KEYWORD_INT IDENTIFIER SEMICOLON {
        emit_declaration($2, "int");
    }
    | KEYWORD_NUM IDENTIFIER SEMICOLON {
        emit_declaration($2, "num");
    }
    ;

assignment:
    IDENTIFIER OP_ASSIGN expression SEMICOLON {
        char* var_type = get_symbol_type($1);
        char* expr_type = get_symbol_type($3); 
        if (var_type == NULL) {
            yyerror("Undeclared variable used in assignment");
        } else if (expr_type != NULL && strcmp(var_type, expr_type) != 0) {
            yyerror("Type mismatch in assignment");
        } else if (expr_type == NULL) {
            emit_assignment($1, "num"); // Assigning a constant
        } else {
            emit_assignment($1, $3);
        }
    }
    ;

if_statement:
    KEYWORD_IF LPAREN condition RPAREN LBRACE statement_list RBRACE {
        emit("IF %s THEN\n", $3);
        emit("%s", $6);
        emit("ENDIF\n");
    }
    | KEYWORD_IF LPAREN condition RPAREN LBRACE statement_list RBRACE KEYWORD_ELSE LBRACE statement_list RBRACE {
        emit("IF %s THEN\n", $3);
        emit("%s", $6);
        emit("ELSE\n");
        emit("%s", $10);
        emit("ENDIF\n");
    }
    ;

while_statement:
    KEYWORD_WHILE LPAREN condition RPAREN LBRACE statement_list RBRACE {
        emit("WHILE %s DO\n", $3);
        emit("%s", $6);
        emit("ENDWHILE\n");
    }
    ;

read_statement:
    KEYWORD_READ LPAREN IDENTIFIER RPAREN SEMICOLON {
        if (get_symbol_type($3) == NULL) {
            yyerror("Undeclared variable used in read statement");
        } else {
            emit("READ %s\n", $3);
        }
    }
    ;

write_statement:
    KEYWORD_WRITE LPAREN expression RPAREN SEMICOLON {
        emit("WRITE %s\n", $3);
    }
    ;

stop_statement:
    KEYWORD_STOP SEMICOLON {
        emit("STOP\n");
    }
    ;

statement_list:
    statement
    | statement_list statement
    ;

condition:
    expression OP_EQUAL expression {
        emit_comparison($1, $3, "=");
        $$ = strdup_safe("RESULT");
    }
    | expression OP_NOT_EQUAL expression {
        emit_comparison($1, $3, "!=");
        $$ = strdup_safe("RESULT");
    }
    | expression OP_LESS_THAN expression {
        emit_comparison($1, $3, "<");
        $$ = strdup_safe("RESULT");
    }
    | expression OP_GREATER_THAN expression {
        emit_comparison($1, $3, ">");
        $$ = strdup_safe("RESULT");
    }
    | expression OP_LESS_EQUAL expression {
        emit_comparison($1, $3, "<=");
        $$ = strdup_safe("RESULT");
    }
    | expression OP_GREATER_EQUAL expression {
        emit_comparison($1, $3, ">=");
        $$ = strdup_safe("RESULT");
    }
    ;

expression:
    IDENTIFIER {
        if (get_symbol_type($1) == NULL) {
            yyerror("Undeclared variable used in expression");
        } else {
            $$ = strdup_safe($1);
        }
    }
    | NUMBER_CONST {
        $$ = strdup_safe(yytext);
    }
    | expression OP_PLUS expression {
        emit("ADD %s %s\n", $1, $3);
        $$ = strdup_safe("RESULT");
    }
    | expression OP_MINUS expression {
        emit("SUB %s %s\n", $1, $3);
        $$ = strdup_safe("RESULT");
    }
    | expression OP_MULTIPLY expression {
        emit("MUL %s %s\n", $1, $3);
        $$ = strdup_safe("RESULT");
    }
    | expression OP_DIVIDE expression {
        emit("DIV %s %s\n", $1, $3);
        $$ = strdup_safe("RESULT");
    }
    | LPAREN expression RPAREN {
        $$ = $2;
    }
    ;

%%
