#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

StackT stack_init() {
    return (StackT) {
        .arr = NULL,
        .size = 0,
    };
}

bool push(StackT* stack, Student s) {
    Student n;
    char* name = strdup(s.name);
    char* surename = strdup(s.surename);

    n.name = name;
    n.surename = surename;
    n.birth_year = s.birth_year;

    if (stack->arr == NULL) {
        stack->arr = malloc(sizeof(Student));
    }

    if (sizeof(stack->arr) <= (stack->size + 1) * sizeof(Student)) {
        stack->arr = realloc(stack->arr, (stack->size + 1) * sizeof(Student));
    }

    if (stack->arr == NULL) {
        printf("memory allocation failure\n");
        return false;
    }

    stack->arr[stack->size] = n;
    stack->size++;

    return true;
}

bool pop(StackT* stack, Student* result) {
    *result = stack->arr[stack->size - 1];

    stack->size--;
    
    return true;
}

void find(StackT* stack, char* surename) {
    Student temp;
    int i;

    for (i = 0; i < stack->size; i++) {
        temp = stack->arr[i];

        if (strcmp(temp.surename, surename) == 0) {
            print_student(temp);
        }
    }
}

void print(StackT* stack) {
    int i;

    for (i = 0; i < stack->size; i++) {
        print_student(stack->arr[i]);
    }
}

void drop(StackT* stack) {
    int i;

    for (i = 0; i < stack->size; i++) {
        free_student(&stack->arr[i]);
    }

    free(stack->arr);

    stack->arr = NULL;
    stack->size = 0;
}
