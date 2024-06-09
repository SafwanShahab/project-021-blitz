#include "mil.h"

symbol symbol_table[100];
int symbol_count = 0;

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

void add_symbol(const char* name, const char* type) {
    symbol_table[symbol_count].name = strdup_safe(name);
    symbol_table[symbol_count].type = strdup_safe(type);
    symbol_count++;
}

char* get_symbol_type(const char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].type;
        }
    }
    return NULL;
}

void emit_declaration(const char* var, const char* type) {
    emit("DECLARE %s %s\n", var, type);
    add_symbol(var, type);
}

void emit_assignment(const char* var, const char* expr) {
    emit("ASSIGN %s %s\n", var, expr);
}

void emit_comparison(const char* left, const char* right, const char* op) {
    emit("COMPARE %s %s %s\n", left, op, right);
}

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
