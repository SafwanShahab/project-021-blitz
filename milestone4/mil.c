#include "mil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void emit(const char* instruction, const char* arg1, const char* arg2) {
    if (arg1 && arg2) {
        printf("%s %s %s\n", instruction, arg1, arg2);
    } else if (arg1) {
        printf("%s %s\n", instruction, arg1);
    } else {
        printf("%s\n", instruction);
    }
}

ASTNode* createNode(const char* token, ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->token = strdup(token);
    node->left = left;
    node->right = right;
    return node;
}
