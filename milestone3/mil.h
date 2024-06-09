#ifndef MIL_H
#define MIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "blitz.tab.h"  // Include the Bison header to get YYSTYPE declaration

void yyerror(const char* s);
int yylex(void);

extern FILE* yyin;
extern int yylineno;
extern char* yytext;

typedef struct {
    char* name;
    char* type;
} symbol;

extern symbol symbol_table[100]; // Declare symbol_table as extern
extern int symbol_count; // Declare symbol_count as extern

char* strdup_safe(const char* s);
void emit(const char* format, ...);
void add_symbol(const char* name, const char* type);
char* get_symbol_type(const char* name);
void emit_declaration(const char* var, const char* type);
void emit_assignment(const char* var, const char* expr);
void emit_comparison(const char* left, const char* right, const char* op);

#endif /* MIL_H */
