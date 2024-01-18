#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACK_SIZE 100
typedef struct {
    int arr[STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *stack);
int isEmpty(Stack *stack);

void push(Stack *stack, int value);

void pall(Stack *stack);
void processMontyScript(FILE *file, Stack *stack);
#endif
