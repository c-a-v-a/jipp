#ifndef GAUSS_H
#define GAUSS_H

void gaussElimination(double** M, int rows, int cols);

void gaussReverse(double** M, int rows, int cols);

double det(double** M, int n);

#endif
