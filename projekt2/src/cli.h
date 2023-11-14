#ifndef CLI_H
#define CLI_H

const static short MINIMUM_PARAMS = 3;
const static short MAXIMUM_PARAMS = 4;

const static short MAX_FLAG_LENGTH = 4;
const static char* L_SEARCH_FLAG = "-s";
const static char* R_SEARCH_FLAG = "-e";
const static char* LR_SEARCH_FLAG = "-se";

enum FLAG_STATE {
    EMPTY,
    L_SEARCH,
    R_SEARCH,
    LR_SEARCH,
    INCORRECT
};

struct ParsedArgs {
    FILE* file;
    char* pattern;
    enum FLAG_STATE flag;
};

void print_help();

int parse(int argc, char* argv[], struct ParsedArgs* parsed);

enum FLAG_STATE parse_flag(char* flag);

#endif
