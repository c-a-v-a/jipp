#include <stdio.h>

#include "error.h"
#include "input.h"
#include "series.h"

int read_input(struct Parameters* input) {
    double* range_min = &(input->range_min);
    double* range_max = &(input->range_max);
    double* epsilon = &(input->epsilon);

    int scanned_args;
    int unsigned_temp;

    // range input
    printf("Approximation domain (min max): ");
    scanned_args = scanf("%lf %lf", range_min, range_max);

    if (scanned_args != RANGE_INPUTS) {
        fprintf(stderr, "Error. Invalid input format.\n");
        return INVALID_INPUT;
    }

    if (0 > range_min || range_min > range_max) {
        fprintf(stderr, "Error. Invalid values. Expected (0 < min < max).\n");
        return INVALID_VALUE;
    }

    // precision input
    printf("Approximation precision: ");
    scanned_args = scanf("%lf", epsilon);

    if (scanned_args != PRECISION_INPUTS) {
        fprintf(stderr, "Error. Invalid input format.\n");
        return INVALID_INPUT;
    }

    if (0 >= epsilon) {
        fprintf(stderr, "Error. Invalid values. Expected (epsilon > 0).\n");
        return INVALID_VALUE;
    }

    // points input
    printf("Number of points to approximate in given range: ");
    scanned_args = scanf("%d", &unsigned_temp);

    if (scanned_args != POINTS_INPUTS) {
        fprintf(stderr, "Error. Invalid input format.\n");
        return INVALID_INPUT;
    }

    if (0 >= unsigned_temp) {
        fprintf(stderr, "Error. Invalid values. Expected (points > 0).\n");
        return INVALID_VALUE;
    }

    input->points = unsigned_temp;

    // series length input
    printf("Length of the power series: ");
    scanned_args = scanf("%d", &unsigned_temp);

    if (scanned_args != SERIES_INPUTS) {
        fprintf(stderr, "Error. Invalid input format.\n");
        return INVALID_INPUT;
    }

    if (0 >= unsigned_temp) {
        fprintf(stderr, "Error. Invalid values. Expected (length > 0).\n");
        return INVALID_VALUE;
    }

    input->series_length = unsigned_temp;

    return SUCCESS;
}
