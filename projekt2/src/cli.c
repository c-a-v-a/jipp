#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "cli.h"
#include "error.h"

void print_help() {
    printf("cg - grep clone written in c.\n");
    printf("USAGE: gc [...OPTIONS] <PATTERN> <FILE>\n");
    printf("OPTIONS:\n");
    printf("\t-s - find pattern from the beginning of the line\n");
    printf("\t-e - find pattern from the end of the line\n");
    printf("\t-se - find pattern from the begginig and end of the line\n");
    printf("\twithout flags - find pattern in any place in the line\n");

    return;
}

int parse(int argc, char* argv[], struct ParsedArgs* parsed) {
    FILE* file;

    if (argc < MINIMUM_PARAMS || argc > MAXIMUM_PARAMS) {
        print_help();
        return ARG_ERROR;
    }

    if (argv[1][0] == '-') {
        parsed->flag = parse_flag(argv[1]);
        parsed->pattern = argv[2];
    } else {
        parsed->flag = EMPTY;
        parsed->pattern = argv[1];
    }

    if (parsed->flag == INCORRECT) {
        printf("Error. Incorrect option given.\n");
        return ARG_ERROR;
    }

    file = fopen(argv[argc - 1], "r");

    if (file == NULL) {
        printf("Error. Incorect file name.\n");
        return FILE_ERROR;
    }

    parsed->file = file;

    return SUCCESS;
}

enum FLAG_STATE parse_flag(char* flag) {
    if (strncmp(flag, L_SEARCH_FLAG, MAX_FLAG_LENGTH) == 0) {
        return L_SEARCH;
    } else if (strncmp(flag, R_SEARCH_FLAG, MAX_FLAG_LENGTH) == 0) {
        return R_SEARCH;
    } else if (strncmp(flag, LR_SEARCH_FLAG, MAX_FLAG_LENGTH) == 0) {
        return LR_SEARCH;
    } else {
        return INCORRECT;
    }
}
