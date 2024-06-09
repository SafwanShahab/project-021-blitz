#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* type;
} Symbol;

typedef struct {
    Symbol* symbols;
    int size;
    int capacity;
} SymbolTable;

extern SymbolTable* table;

void init_table();
void add_symbol(const char* name, const char* type);
Symbol* get_symbol(const char* name);
void free_table();

#endif 
