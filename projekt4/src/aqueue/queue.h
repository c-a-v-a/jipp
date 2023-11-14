#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#include "../student.h"

typedef struct Queue QueueT;

struct Queue {
    Student* arr;
    unsigned int size;
};

QueueT queue_init();

bool push(QueueT* queue, Student element);

bool pop(QueueT* queue, Student* result);

void find(QueueT* queue, char* surename);

void print(QueueT* queue);

int count(QueueT* queue);

void drop(QueueT* queue);

#endif
