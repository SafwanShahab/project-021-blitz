#include "table.h"

SymbolTable* table = NULL;

void init_table() {
    table = (SymbolTable*)malloc(sizeof(SymbolTable));
    table->size = 0;
    table->capacity = 10;
    table->symbols = (Symbol*)malloc(table->capacity * sizeof(Symbol));
}

void add_symbol(const char* name, const char* type) {
    if (table->size >= table->capacity) {
        table->capacity *= 2;
        table->symbols = (Symbol*)realloc(table->symbols, table->capacity * sizeof(Symbol));
    }
    table->symbols[table->size].name = strdup(name);
    table->symbols[table->size].type = strdup(type);
    table->size++;
}

Symbol* get_symbol(const char* name) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->symbols[i].name, name) == 0) {
            return &table->symbols[i];
        }
    }
    return NULL;
}

void free_table() {
    for (int i = 0; i < table->size; i++) {
        free(table->symbols[i].name);
        free(table->symbols[i].type);
    }
    free(table->symbols);
    free(table);
}
