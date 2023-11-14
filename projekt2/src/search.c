#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "search.h"

bool search_any(char* pattern, char* line) {
    size_t pattern_len = strlen(pattern);
    size_t line_len = strlen(line);
    int pattern_i = 0;
    int line_i;

    for (line_i = 0; line_i < line_len; line_i++) {
       if (pattern[pattern_i] == line[line_i]) {
            pattern_i++;
       } else if (pattern_i != 0) {
            // decrement line index to make sure that doubled letters don't 
            // screw up the search
            line_i--;
            pattern_i = 0;
       }

       if (pattern_i == pattern_len) {
            return true;
       }
    }

    return false;
}

bool searchl(char* pattern, char* line) {
    size_t pattern_len = strlen(pattern);
    size_t line_len = strlen(line);
    int pattern_i = 0;
    int line_i;

    for (line_i = 0; line_i < line_len; line_i++) {
       if (pattern[pattern_i] == line[line_i]) {
            pattern_i++;
       } else {
            return false;
       }

       if (pattern_i == pattern_len) {
            return true;
       }
    }

    return false;
}

bool searchr(char* pattern, char* line) {
    size_t pattern_len = strlen(pattern);
    size_t line_len = strlen(line);
    int pattern_i = pattern_len - 1;
    int line_i;

    // len - 2 to account for counting from 0 and '\n'
    for (line_i = line_len - 2; line_i >= 0; line_i--) {
        if (pattern[pattern_i] == line[line_i]) {
            pattern_i--;
        } else {
            return false;
        }

        if (pattern_i == -1) {
            return true;
        }
    }

    return false;
}
