#include <string.h>
#include <stdio.h>

#include "strlib.h"

void strip_newline(char* str) {
    size_t len = strlen(str);

    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void flush_in() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {}
}
