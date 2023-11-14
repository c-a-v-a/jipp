#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

void free_matrix(double** M, int rows, int cols) {
    int i;

    for (i = 0; i < rows; i++) {
        free(M[i]);
    }
    
    free(M);
}

void print_matrix(double** M, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%lf ", M[i][j]);
        }
        printf("\n");
    }
}
