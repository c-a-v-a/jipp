#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

QueueT queue_init() {
    return (QueueT) {
        .top = NULL,
        .size = 0,
    };
}

bool push(QueueT* queue, Student s) {
    NodeT* n = (NodeT*)malloc(sizeof(NodeT));
    NodeT* temp;
    char* name = strdup(s.name);
    char* surename = strdup(s.surename);

    if (n == NULL) {
        return false;
    }

    n->value.name = name;
    n->value.surename = surename;
    n->value.birth_year = s.birth_year;
    n->next = NULL;

    if (queue->top == NULL) {
        queue->top = n;
        queue->size++;

        return true;
    }

    temp = queue->top;

    while (1) {
        if (temp->next == NULL) {
            temp->next = n;
            break;
        }

        temp = temp->next;
    }

    queue->size++;

    return true;
}

bool pop(QueueT* queue, Student* result) {
    NodeT* n = queue->top;

    if (n == NULL) {
        return false;
    }
    
    *result = n->value;
    
    queue->top = n->next;
    queue->size--;

    free(n);

    return true;
}

void find(QueueT* queue, char* surename) {
    NodeT* n = queue->top;

    while(n != NULL) {
        if(strcmp(n->value.surename, surename) == 0) {
            print_student(n->value);
        }

        n = n->next;
    }
}

void print(QueueT* queue) {
    NodeT* n = queue->top;

    while(n != NULL) {
        print_student(n->value);

        n = n->next;
    }
}

void drop(QueueT* queue) {
    NodeT* n = queue->top;

    if (n == NULL) {
        return;
    }

    while (n != NULL) {
        queue->top = queue->top->next;

        free_student(&n->value);
        free(n);

        n = queue->top;
    }

    queue->top = NULL;
    queue->size = 0;
}
