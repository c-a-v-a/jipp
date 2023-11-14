#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdbool.h>

bool search_any(char* pattern, char* line);

bool searchl(char* pattern, char* line);

bool searchr(char* pattern, char* line);

#endif
