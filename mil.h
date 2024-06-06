#ifndef MIL_INSTRUCTIONS_H
#define MIL_INSTRUCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for MIL instructions
typedef struct {
    char* instruction;
    char* operand1;
    char* operand2;
} MILInstruction;

// Function to create a MIL instruction
MILInstruction* create_instruction(const char* instruction, const char* operand1, const char* operand2) {
    MILInstruction* inst = (MILInstruction*)malloc(sizeof(MILInstruction));
    inst->instruction = strdup(instruction);
    inst->operand1 = operand1 ? strdup(operand1) : NULL;
    inst->operand2 = operand2 ? strdup(operand2) : NULL;
    return inst;
}

// Function to print a MIL instruction
void print_instruction(MILInstruction* inst) {
    if (inst->operand1 && inst->operand2) {
        printf("%s %s %s\n", inst->instruction, inst->operand1, inst->operand2);
    } else if (inst->operand1) {
        printf("%s %s\n", inst->instruction, inst->operand1);
    } else {
        printf("%s\n", inst->instruction);
    }
}

// Function to free a MIL instruction
void free_instruction(MILInstruction* inst) {
    if (inst->instruction) free(inst->instruction);
    if (inst->operand1) free(inst->operand1);
    if (inst->operand2) free(inst->operand2);
    free(inst);
}

#endif // MIL_INSTRUCTIONS_H
