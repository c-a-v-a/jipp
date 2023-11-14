#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "../student.h"

typedef struct Node NodeT;
typedef struct Queue QueueT;

struct Node {
    Student value;
    struct Node* next;
};

struct Queue {
    struct Node* top;
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
