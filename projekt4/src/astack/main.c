#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "../menu.h"
#include "../student.h"
#include "../strlib.h"

int main() {
    StackT stack = stack_init();
    Student temp;
    int user_input;
    char* find_str;
    short scanned_args;
    size_t read_len = 256;

    do {
        print_menu();

        printf("INPUT: ");
        scanned_args = scanf("%d", &user_input);
        flush_in();

        if (scanned_args != 1) {
            printf("bad input\n\n");
            continue;
        }

        switch (user_input) {
            case ADD:
                if (!get_student(&temp)) {
                    break;
                }

                if(!push(&stack, temp)) {
                    printf("could not add student\n");
                    break;
                }

                printf("ADDED\n");
                print_student(temp);

                free_student(&temp);

                break;
            case GET:
                if (!pop(&stack, &temp)) {
                    printf("could not get element\n");
                    break;
                }

                printf("POPPED\n");
                print_student(temp);

                free_student(&temp);

                break;
            case FIND:
                printf("surename: ");
                scanned_args = getline(&find_str, &read_len, stdin);
                if (scanned_args == -1) {
                    printf("bad format\n");
                    break;
                }

                strip_newline(find_str);
                find(&stack, find_str);

                free(find_str);

                break;
            case PRINT:
                printf("STACK\n");
                print(&stack);

                break;
            case SIZE:
                printf("%d", stack.size);

                break;
            case EXIT:
                break;
            default:
                printf("bad input\n");
                break;
        }

        printf("\n");
    } while (user_input != EXIT);

    drop(&stack);

    return 0;
}
