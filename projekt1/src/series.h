#ifndef SERIES_H
#define SERIES_H

#include <stdbool.h>

struct Parameters {
    unsigned int points;
    unsigned int series_length;
    double range_min;
    double range_max;
    double epsilon;
};

struct Approximation {
    double value;
    bool is_precise;
};

struct Approximation ln(double x, double series_length, double epsilon);

#endif
