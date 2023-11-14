#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

QueueT queue_init() {
    return (QueueT) {
        .arr = NULL,
        .size = 0,
    };
}

void shift_array(Student* arr, unsigned int len) {
    Student temp = arr[0];
    int i;

    for (i = 1; i < len; i++) {
        arr[i - 1] = arr[i];
    }

    arr[len - 1] = temp;
}

bool push(QueueT* queue, Student s) {
    Student n;
    char* name = strdup(s.name);
    char* surename = strdup(s.surename);

    n.name = name;
    n.surename = surename;
    n.birth_year = s.birth_year;

    if (queue->arr == NULL) {
        queue->arr = malloc(sizeof(Student));
    }

    if (sizeof(queue->arr) <= (queue->size + 1) * sizeof(Student)) {
        queue->arr = realloc(queue->arr, (queue->size + 1) * sizeof(Student));
    }

    if (queue->arr == NULL) {
        printf("memory allocation failure\n");
        return false;
    }

    queue->arr[queue->size] = n;
    queue->size++;

    return true;
}

bool pop(QueueT* queue, Student* result) {
    *result = queue->arr[0];

    shift_array(queue->arr, queue->size);

    queue->size--;
    
    return true;
}

void find(QueueT* queue, char* surename) {
    Student temp;
    int i;

    for (i = 0; i < queue->size; i++) {
        temp = queue->arr[i];

        if (strcmp(temp.surename, surename) == 0) {
            print_student(temp);
        }
    }
}

void print(QueueT* queue) {
    int i;

    for (i = 0; i < queue->size; i++) {
        print_student(queue->arr[i]);
    }
}

void drop(QueueT* queue) {
    int i;

    for (i = 0; i < queue->size; i++) {
        free_student(&queue->arr[i]);
    }

    free(queue->arr);

    queue->arr = NULL;
    queue->size = 0;
}
