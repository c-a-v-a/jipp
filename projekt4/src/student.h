#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char* name;
    char* surename;
    unsigned int birth_year;
} Student;

Student student_init(char* name, char* surename, unsigned int birth_year);

void free_student(Student* student);

void print_student(Student student);

bool get_student(Student* student);

#endif
