#include "gauss.h"

void gaussElimination(double** M, int rows, int cols) {
    int i, j, k;

    for (i = 0; i < rows; i++) {
        for (k = i + 1; k < rows; k++) {
            double frac = M[k][i] / M[i][i];

            for (j = i; j < cols; j++) {
                M[k][j] -= frac * M[i][j];
            }
        }
    }
}

void gaussReverse(double** M, int rows, int cols) {
    int i, j, k;

    for (i = rows - 1; i >= 0; i--) {
        for (j = rows; j < cols; j++) {
            M[i][j] /= M[i][i];
        }

        // M[i][i] /= M[i][i];
        M[i][i] = 1;

        for (j = i - 1; j >= 0; j--) {
            for (k = cols - 1; k >= rows - 1; k--) {
                M[j][k] -= M[j][i] * M[i][k];
            }
        }

    }
}

double det(double** M, int n) {
    int i;
    double det = 1;

    gaussElimination(M, n, n);

    for (i = 0; i < n; i++) {
        det *= M[i][i];
    }

    return det;
}
