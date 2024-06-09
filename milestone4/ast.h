#ifndef AST_H
#define AST_H

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
    return node;
}

#endif 
