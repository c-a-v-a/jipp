#ifndef INPUT_H
#define INPUT_H

#include "series.h"

// correct inputs
const static short RANGE_INPUTS = 2;
const static short PRECISION_INPUTS = 1;
const static short POINTS_INPUTS = 1;
const static short SERIES_INPUTS = 1;

// table formats
const static char* header = "| %-5s | %-15s | %-15s | %-15s | %-10s |\n";
const static char* row = "| %-5.2lf | %-15.5lf | %-15.5lf | %-15d | %-10s |\n";

// read input parameters from stdin
int read_input(struct Parameters* input);

#endif
