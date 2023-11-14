#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrix.h"
#include "gauss.h"

int main() {
    // iterators
    int i, j;
    bool bad_input = false;

    int n, m;
    double** A;
    double** B;
    double** AB;
    double** I;
    double** AI;
    double detA;

    double scan_temp;
    int scanned_args;

    printf("A size: ");
    scanned_args = scanf("%d", &n);

    if (scanned_args != 1 || n < 1) {
        printf("error. invalid input.\n");
        return 0;
    }

    printf("Right sides: ");
    scanned_args = scanf("%d", &m);

    if (scanned_args != 1 || m < 1) {
        printf("error. invalid input.\n");
        return 0;
    }

    // Matrix init
    A = (double**)malloc(n*  sizeof(double*));
    for (i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
    }

    B = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        B[i] = (double*)malloc(m * sizeof(double));
    }

    AB = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        AB[i] = (double*)malloc((n + m) * sizeof(double));
    }

    // identity matrix
    I = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        I[i] = (double*)malloc(n * sizeof(double));
    }

    AI = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        AI[i] = (double*)malloc(2 * n * sizeof(double));
    }

    printf("Input matrix A\n");
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanned_args = scanf("%lf", &scan_temp);
            if (scanned_args != 1)
                bad_input = true;

            A[i][j] = scan_temp;
            AB[i][j] = scan_temp;
        }
    }

    if (bad_input) {
        printf("bad input.\n");

        free_matrix(A, n, n);
        free_matrix(B, n, m);
        free_matrix(AB, n, n + m);

        return 0;
    }

    printf("Input matrix B\n");
    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanned_args = scanf("%lf", &scan_temp);
            if (scanned_args != 1)
                bad_input = true;

            B[i][j] = scan_temp;
            AB[i][n + j] = scan_temp;
        }
    }

    if (bad_input) {
        printf("bad input.\n");

        free_matrix(A, n, n);
        free_matrix(B, n, m);
        free_matrix(AB, n, n + m);

        return 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            I[i][j] = i == j ? 1 : 0;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < 2 * n; j++) {
            AI[i][j] = j < n ? A[i][j] : I[i][j - n];
        }
    }

    // system of equations solutions
    gaussElimination(AB, n, n + m);
    gaussReverse(AB, n, n + m);

    printf("\nsolution: \n");
    for (i = 0; i < n; i++) {
        for (j = n; j < n + m; j++) {
            printf("x%d%d = %lf\n", i + 1, j - n + 1, AB[i][j]);
        }
    }

    // det(A)
    detA = det(A, n);

    printf("\ndet(A)=%lf\n\n", detA);

    // A^(-1)
    if (detA == 0) {
        printf("Matrix A^(-1) does not exist.\n");
    } else {
        gaussElimination(AI, n, 2 * n);
        gaussReverse(AI, n, 2 * n);

        printf("A^(-1): \n");
        for (i = 0; i < n; i++) {
            for (j = n; j < 2 * n; j++) {
                printf("%lf ", AI[i][j]);
            }
            printf("\n");
        }
    }

    free_matrix(A, n, n);
    free_matrix(B, n, m);
    free_matrix(AB, n, n + m);
    free_matrix(I, n, n);
    free_matrix(AI, n, 2 * n);
}
