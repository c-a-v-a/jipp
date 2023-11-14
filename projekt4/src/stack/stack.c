#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

StackT stack_init() {
    return (StackT) {
        .top = NULL,
        .size = 0,
    };
}

bool push(StackT* stack, Student s) {
    NodeT* n = (NodeT*)malloc(sizeof(NodeT));
    char* name = strdup(s.name);
    char* surename = strdup(s.surename);

    if (n == NULL) {
        return false;
    }

    n->value.name = name;
    n->value.surename = surename;
    n->value.birth_year = s.birth_year;
    n->next = stack->top;

    stack->top = n;
    stack->size++;

    return true;
}

bool pop(StackT* stack, Student* result) {
    NodeT* n = stack->top;

    if (n == NULL) {
        return false;
    }
    
    *result = n->value;
    
    stack->top = n->next;
    stack->size--;

    free(n);

    return true;
}

void find(StackT* stack, char* surename) {
    NodeT* n = stack->top;

    while(n != NULL) {
        if(strcmp(n->value.surename, surename) == 0) {
            print_student(n->value);
        }

        n = n->next;
    }
}

void print(StackT* stack) {
    NodeT* n = stack->top;

    while(n != NULL) {
        print_student(n->value);

        n = n->next;
    }
}

/*
int count(StackT* stack) {
    return stack->size;
}
*/


void drop(StackT* stack) {
    NodeT* n = stack->top;

    if (n == NULL) {
        return;
    }

    while (n != NULL) {
        stack->top = stack->top->next;

        free_student(&n->value);
        free(n);

        n = stack->top;
    }

    stack->top = NULL;
    stack->size = 0;
}
