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

// Function declarations
MILInstruction* create_instruction(const char* instruction, const char* operand1, const char* operand2);
void print_instruction(MILInstruction* inst);
void free_instruction(MILInstruction* inst);

#endif // MIL_INSTRUCTIONS_H
