#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#include "../student.h"

typedef struct Node NodeT;
typedef struct Stack StackT;

struct Node {
    Student value;
    struct Node* next;
};

struct Stack {
    struct Node* top;
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
