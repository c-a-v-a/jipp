#include <stdio.h>

#include "menu.h"

void print_menu() {
    printf("select option: \n");
    printf("%d: add\n",   ADD);
    printf("%d: get\n",   GET);
    printf("%d: find\n",  FIND);
    printf("%d: print\n", PRINT);
    printf("%d: size\n",  SIZE);
    printf("%d: exit\n",  EXIT);
}
