%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void yyerror(const char* s);
int yylex(void);

extern FILE* yyin;
extern int yylineno;
extern char* yytext;

char* strdup_safe(const char* s) {
    size_t len = strlen(s) + 1;
    char* copy = (char*)malloc(len);
    if (copy) {
        memcpy(copy, s, len);
    }
    return copy;
}

void emit(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void emit_declaration(const char* var, const char* type) {
    emit("DECLARE %s %s\n", var, type);
}

void emit_assignment(const char* var, const char* expr) {
    emit("ASSIGN %s %s\n", var, expr);
}

void emit_if_start(const char* expr) {
    emit("IF %s THEN\n", expr);
}

void emit_if_end() {
    emit("ENDIF\n");
}

void emit_else_start() {
    emit("ELSE\n");
}

void emit_while_start(const char* expr) {
    emit("WHILE %s DO\n", expr);
}

void emit_while_end() {
    emit("ENDWHILE\n");
}

void emit_for_start(const char* init, const char* cond) {
    emit("%s\n", init);  // Emit initialization
    emit("FOR_START:\n");
    emit("IF NOT %s THEN GOTO END_FOR\n", cond);  // Emit condition check
}

void emit_for_body_start() {
    emit("FOR_BODY_START:\n");
}

void emit_for_end(const char* update) {
    emit("%s\n", update);  // Emit update
    emit("GOTO FOR_START\n");
    emit("END_FOR:\n");
}

void emit_read(const char* var) {
    emit("READ %s\n", var);
}

void emit_write(const char* expr) {
    emit("WRITE %s\n", expr);
}

void emit_stop() {
    emit("STOP\n");
}

void emit_array_declaration(const char* var, const char* type, int size) {
    emit("DECLARE ARRAY %s %s %d\n", var, type, size);
}

void emit_array_assignment(const char* var, const char* index, const char* expr) {
    emit("ASSIGN %s[%s] %s\n", var, index, expr);
}

void emit_array_access(const char* var, const char* index) {
    emit("ACCESS %s[%s]\n", var, index);
}
%}

%union {
    int num;
    char* str;
}

%token <num> NUMBER
%token <str> IDENTIFIER
%token KEYWORD_INT KEYWORD_NUM KEYWORD_IF KEYWORD_ELSE KEYWORD_WHILE KEYWORD_STOP KEYWORD_READ KEYWORD_WRITE
%token KEYWORD_FOR KEYWORD_FUNC KEYWORD_RETURN
%token OP_ASSIGN OP_EQUAL OP_EQUAL_EQUAL OP_NOT_EQUAL OP_LESS_THAN OP_GREATER_THAN OP_LESS_EQUAL OP_GREATER_EQUAL
%token OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVIDE
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE BEGINLOOP ENDLOOP
%token LBRACKET RBRACKET

%type <str> assignment if_statement while_statement for_statement write_statement expression
%type <str> declaration read_statement stop_statement
%type <str> statement statement_list
%type <str> array_declaration array_assignment array_access

%right OP_ASSIGN
%left OP_PLUS OP_MINUS
%left OP_MULTIPLY OP_DIVIDE
%nonassoc OP_EQUAL OP_NOT_EQUAL OP_LESS_THAN OP_GREATER_THAN OP_LESS_EQUAL OP_GREATER_EQUAL

%%

program:
    statement_list { printf("Program parsed successfully.\n"); }
    ;

statement_list:
    statement { $$ = $1; }
    | statement_list statement { $$ = $1; }
    ;

statement:
    declaration
    | assignment
    | if_statement
    | while_statement
    | for_statement
    | read_statement
    | write_statement
    | stop_statement
    | array_declaration
    | array_assignment
    | array_access
    ;

declaration:
    KEYWORD_INT IDENTIFIER SEMICOLON {
        emit_declaration($2, "INT");
    }
    | KEYWORD_NUM IDENTIFIER SEMICOLON {
        emit_declaration($2, "NUM");
    }
    ;

assignment:
    IDENTIFIER OP_ASSIGN expression SEMICOLON {
        emit_assignment($1, $3);
    }
    ;

if_statement:
    KEYWORD_IF LPAREN expression RPAREN LBRACE statement_list RBRACE {
        emit_if_start($3);
        emit_if_end();
    }
    | KEYWORD_IF LPAREN expression RPAREN LBRACE statement_list RBRACE KEYWORD_ELSE LBRACE statement_list RBRACE {
        emit_if_start($3);
        emit_else_start();
        emit_if_end();
    }
    ;

while_statement:
    KEYWORD_WHILE LPAREN expression RPAREN LBRACE statement_list RBRACE {
        emit_while_start($3);
        emit_while_end();
    }
    ;

for_statement:
    KEYWORD_FOR LPAREN assignment expression SEMICOLON assignment RPAREN LBRACE statement_list RBRACE {
        emit_for_start($3, $4);
        emit_for_body_start();
        emit_for_end($6);
    }
    ;

read_statement:
    KEYWORD_READ LPAREN IDENTIFIER RPAREN SEMICOLON {
        emit_read($3);
    }
    ;

write_statement:
    KEYWORD_WRITE LPAREN expression RPAREN SEMICOLON {
        emit_write($3);
    }
    ;

stop_statement:
    KEYWORD_STOP SEMICOLON {
        emit_stop();
    }
    ;

array_declaration:
    KEYWORD_INT IDENTIFIER LBRACKET NUMBER RBRACKET SEMICOLON {
        emit_array_declaration($2, "INT", $4);
    }
    | KEYWORD_NUM IDENTIFIER LBRACKET NUMBER RBRACKET SEMICOLON {
        emit_array_declaration($2, "NUM", $4);
    }
    ;

array_assignment:
    IDENTIFIER LBRACKET expression RBRACKET OP_ASSIGN expression SEMICOLON {
        emit_array_assignment($1, $3, $6);
    }
    ;

array_access:
    IDENTIFIER LBRACKET expression RBRACKET SEMICOLON {
        emit_array_access($1, $3);
    }
    ;

expression:
    IDENTIFIER {
        $$ = strdup_safe($1);
    }
    | NUMBER {
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
    | expression OP_LESS_THAN expression {
        emit("LESS_THAN %s %s\n", $1, $3);
        $$ = strdup_safe("RESULT");
    }
    | expression OP_GREATER_THAN expression {
        emit("GREATER_THAN %s %s\n", $1, $3);
        $$ = strdup_safe("RESULT");
    }
    | LPAREN expression RPAREN {
        $$ = $2;
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main(int argc, char **argv) {
    ++argv, --argc;  /* skip over program name */
    if (argc > 0)
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;

    yyparse();
    return 0;
}
