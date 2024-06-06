%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode {
    char *token;
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

ASTNode* createNode(const char* token, ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->token = strdup(token);
    node->left = left;
    node->right = right;
    printf("Created node: %s\n", token);  // Debugging print
    return node;
}

void printAST(ASTNode* node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s\n", node->token);
    printAST(node->left, level + 1);
    printAST(node->right, level + 1);
}

void yyerror(const char* s);
int yylex(void);

extern FILE* yyin;
extern int yylineno;
extern char* yytext;
extern int col_num;  // Declare col_num here
%}

%union {
    int num;
    char* str;
    struct ASTNode* node;
}

%token <num> NUMBER
%token <str> IDENTIFIER
%token KEYWORD_INT KEYWORD_NUM KEYWORD_IF KEYWORD_ELSE KEYWORD_WHILE KEYWORD_STOP KEYWORD_READ KEYWORD_WRITE
%token OP_ASSIGN OP_EQUAL OP_EQUAL_EQUAL OP_NOT_EQUAL OP_LESS_THAN OP_GREATER_THAN OP_LESS_EQUAL OP_GREATER_EQUAL
%token OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVIDE
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE

%type <node> assignment if_statement while_statement write_statement expression
%type <node> declaration read_statement stop_statement
%type <node> statement statement_list program

%right OP_ASSIGN
%left OP_PLUS OP_MINUS
%left OP_MULTIPLY OP_DIVIDE
%nonassoc OP_EQUAL OP_NOT_EQUAL OP_LESS_THAN OP_GREATER_THAN OP_LESS_EQUAL OP_GREATER_EQUAL

%%

program:
    statement_list { printAST($1, 0); printf("program -> statement_list\n"); }
    ;

statement_list:
    statement { $$ = $1; printf("statement_list -> statement\n"); }
    | statement_list statement { $$ = createNode("statement_list", $1, $2); printf("statement_list -> statement_list statement\n"); }
    ;

statement:
    declaration { $$ = $1; printf("statement -> declaration\n"); }
    | assignment { $$ = $1; printf("statement -> assignment\n"); }
    | if_statement { $$ = $1; printf("statement -> if_statement\n"); }
    | while_statement { $$ = $1; printf("statement -> while_statement\n"); }
    | read_statement { $$ = $1; printf("statement -> read_statement\n"); }
    | write_statement { $$ = $1; printf("statement -> write_statement\n"); }
    | stop_statement { $$ = $1; printf("statement -> stop_statement\n"); }
    ;

declaration:
    KEYWORD_INT IDENTIFIER SEMICOLON { $$ = createNode("declaration", createNode($2, NULL, NULL), NULL); printf("declaration -> KEYWORD_INT IDENTIFIER SEMICOLON\n"); }
    | KEYWORD_NUM IDENTIFIER SEMICOLON { $$ = createNode("declaration", createNode($2, NULL, NULL), NULL); printf("declaration -> KEYWORD_NUM IDENTIFIER SEMICOLON\n"); }
    ;

assignment:
    IDENTIFIER OP_ASSIGN expression SEMICOLON { $$ = createNode("assignment", createNode($1, NULL, NULL), $3); printf("assignment -> IDENTIFIER OP_ASSIGN expression SEMICOLON\n"); }
    ;

if_statement:
    KEYWORD_IF LPAREN expression RPAREN LBRACE statement_list RBRACE { $$ = createNode("if_statement", $3, $6); printf("if_statement -> KEYWORD_IF LPAREN expression RPAREN LBRACE statement_list RBRACE\n"); }
    | KEYWORD_IF LPAREN expression RPAREN LBRACE statement_list RBRACE KEYWORD_ELSE LBRACE statement_list RBRACE { $$ = createNode("if_else_statement", $3, createNode("else", $6, $10)); printf("if_statement -> KEYWORD_IF LPAREN expression RPAREN LBRACE statement_list RBRACE KEYWORD_ELSE LBRACE statement_list RBRACE\n"); }
    ;

while_statement:
    KEYWORD_WHILE LPAREN expression RPAREN LBRACE statement_list RBRACE { $$ = createNode("while_statement", $3, $6); printf("while_statement -> KEYWORD_WHILE LPAREN expression RPAREN LBRACE statement_list RBRACE\n"); }
    ;

read_statement:
    KEYWORD_READ LPAREN IDENTIFIER RPAREN SEMICOLON { $$ = createNode("read_statement", createNode($3, NULL, NULL), NULL); printf("read_statement -> KEYWORD_READ LPAREN IDENTIFIER RPAREN SEMICOLON\n"); }
    ;

write_statement:
    KEYWORD_WRITE LPAREN expression RPAREN SEMICOLON { $$ = createNode("write_statement", $3, NULL); printf("write_statement -> KEYWORD_WRITE LPAREN expression RPAREN SEMICOLON\n"); }
    ;

stop_statement:
    KEYWORD_STOP SEMICOLON { $$ = createNode("stop_statement", NULL, NULL); printf("stop_statement -> KEYWORD_STOP SEMICOLON\n"); }
    ;

expression:
    IDENTIFIER { $$ = createNode($1, NULL, NULL); printf("expression -> IDENTIFIER\n"); }
    | NUMBER { $$ = createNode(yytext, NULL, NULL); printf("expression -> NUMBER\n"); }
    | expression OP_PLUS expression { $$ = createNode("add", $1, $3); printf("expression -> expression OP_PLUS expression\n"); }
    | expression OP_MINUS expression { $$ = createNode("sub", $1, $3); printf("expression -> expression OP_MINUS expression\n"); }
    | expression OP_MULTIPLY expression { $$ = createNode("mul", $1, $3); printf("expression -> expression OP_MULTIPLY expression\n"); }
    | expression OP_DIVIDE expression { $$ = createNode("div", $1, $3); printf("expression -> expression OP_DIVIDE expression\n"); }
    | LPAREN expression RPAREN { $$ = $2; printf("expression -> LPAREN expression RPAREN\n"); }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s at line %d, column %d\n", s, yylineno, col_num);
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
