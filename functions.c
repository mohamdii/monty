#include "monty.h"
#include <stdlib.h>
#define STACK_SIZE 100
void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (stack->top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++(stack->top)] = value;
}

void pall(Stack *stack) {
    int i;
    for (i = stack->top; i >= -1; i--) {
        printf("%d\n", stack->arr[i]);
    }
}
void processMontyScript(FILE *file, Stack *stack) {
    char opcode[20];
    int value;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "Error: Usage - L<line_number>: push integer\n");
                exit(EXIT_FAILURE);
            }
            push(stack, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(stack);
        } else {
            fprintf(stderr, "Error: Unknown opcode - %s\n", opcode);
            exit(EXIT_FAILURE);
        }
    }
}
