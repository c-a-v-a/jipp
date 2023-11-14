#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "strlib.h"
#include "student.h"

Student student_init(char* name, char* surename, unsigned int birth_year) {
    return (Student) {
        .name = name,
        .surename = surename,
        .birth_year = birth_year
    };
}

void free_student(Student* s) {
    free(s->name);
    free(s->surename);
}

void print_student(Student s) {
    printf("\tstudent: %s %s, %d\n", s.name, s.surename, s.birth_year);
}

bool get_student(Student* s) {
    char* name = NULL;
    char* surename = NULL;
    unsigned int birth_year = 0;

    int read;
    size_t read_len = 256;

    printf("student's name: ");
    read = getline(&name, &read_len, stdin);
    if (read == -1) {
        printf("bad format\n");
        return false;
    }

    printf("student's surename: ");
    read = getline(&surename, &read_len, stdin);
    if (read == -1) {
        printf("bad format\n");
        return false;
    }

    printf("student's birth year: ");
    read = scanf("%d", &birth_year);
    if (read != 1) {
        printf("bad format\n");
        return false;
    }

    strip_newline(name);
    strip_newline(surename);

    s->name = name;
    s->surename = surename;
    s->birth_year = birth_year;

    return true;
}
