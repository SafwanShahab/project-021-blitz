#ifndef MIL_H
#define MIL_H

void emit(const char* instruction, const char* arg1, const char* arg2);

typedef struct ASTNode {
    char *token;
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

ASTNode* createNode(const char* token, ASTNode* left, ASTNode* right);

#endif
