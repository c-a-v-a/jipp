#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>

#include "error.h"
#include "input.h"
#include "series.h"

int main() {
    struct Parameters p;
    struct Approximation result;
    short error_code;
    double x;
    double dx;
    const char* info;

    FILE *results_file;

    error_code = read_input(&p);

    if (error_code != SUCCESS) {
        return error_code;
    }

    results_file = fopen("ln_approximation.txt", "w");

    if (results_file == NULL) {
        printf("Error. Could not open file 'ln_approximation.txt'.\n");
        return FILE_ERROR;
    }

    dx = (p.range_max - p.range_min) / (p.points + 1);
    x = p.range_min + dx;

    printf("Approximation for ln(x) in <%.2lf; %.2lf> with power series, and precision = %lf.\n\n",
            p.range_min, p.range_max, p.epsilon);
    fprintf(results_file,
            "Approximation for ln(x) in <%.2lf; %.2lf> with power series, and precision = %lf.\n\n",
            p.range_min, p.range_max, p.epsilon);

    printf(header, 
            "x", "approximation", "ln(x)", "series length", "is precise");
    fprintf(results_file, header, 
            "x", "approximation", "ln(x)", "series length", "is precise");

    while (x < p.range_max) {
        result = ln(x, p.series_length, p.epsilon);
        info = result.is_precise ? "yes" : "no";

        printf(row, x, result.value, log(x), p.series_length, info);
        fprintf(results_file, row, 
                x, result.value, log(x), p.series_length, info);


        x += dx;
    }

    return SUCCESS;
}
