#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#include "../student.h"

typedef struct Stack StackT;

struct Stack {
    Student* arr;
    unsigned int size;
};

StackT stack_init();

bool push(StackT* stack, Student element);

bool pop(StackT* stack, Student* result);

void find(StackT* stack, char* surename);

void print(StackT* stack);

int count(StackT* stack);

void drop(StackT* stack);

#endif
