#include <stdio.h>
#include <stdlib.h>

#include "cli.h"
#include "error.h"
#include "search.h"

int main(int argc, char* argv[]) {
    struct ParsedArgs args;
    int parse_result;
    char* line;
    size_t res = 0;
    ssize_t line_lenght;

    parse_result = parse(argc, argv, &args);

    if (parse_result != SUCCESS) {
        return parse_result;
    }

    switch(args.flag) {
        case EMPTY:
            while ((line_lenght = getline(&line, &res, args.file)) != -1) {
                if (search_any(args.pattern, line)) {
                    printf("%s", line);
                }
            }
            break;
        case L_SEARCH:
            while ((line_lenght = getline(&line, &res, args.file)) != -1) {
                if (searchl(args.pattern, line)) {
                    printf("%s", line);
                }
            }
            break;
        case R_SEARCH:
            while ((line_lenght = getline(&line, &res, args.file)) != -1) {
                if (searchr(args.pattern, line)) {
                    printf("%s", line);
                }
            }
            break;
        case LR_SEARCH:
            while ((line_lenght = getline(&line, &res, args.file)) != -1) {
                if (searchl(args.pattern, line) && searchr(args.pattern, line)) {
                    printf("%s", line);
                }
            }
            break;
    }

    fclose(args.file);

    return SUCCESS;
}
