#include <float.h>
#include <math.h>

#include "series.h"

struct Approximation ln(double x, double series_length, double epsilon) {
    struct Approximation output;
    double expression;
    int i;

    output.value = 0;
    output.is_precise = false;

    for (i = 1; i <= 2 * series_length; i += 2) {
        expression = 2 * pow(x - 1, i) / (i * pow(x + 1, i));

        output.value += expression;

        if (expression < epsilon || fabs(expression - epsilon) <= DBL_EPSILON) {
            output.is_precise = true;
            break;
        }
    }

    return output;
}
