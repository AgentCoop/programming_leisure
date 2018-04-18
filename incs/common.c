#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifdef DEBUG
FILE *__input;

void
init_debug() {
    char input_filename[1024];
    const char *basename = "test/input.txt";

    strcpy(input_filename, PROBLEM_ROOT_DIR);
    strcat(input_filename, basename);

    __input = fopen(input_filename, "r");
}
#endif

#ifdef DEBUG
#undef stdin
#define stdin __input
#endif

#if DEBUG

void
print_expected() {
    char output_filename[1024];
    const char *basename = "test/output.txt";
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    strcpy(output_filename, PROBLEM_ROOT_DIR);
    strcat(output_filename, basename);

    FILE *fd = fopen(output_filename, "r");

    printf("%c[1;32mExpected:%c[0;m\n", 27, 27);

    while ((read = getline(&line, &len, fd)) != -1) {
        printf("%s", line);
    }

    fclose(fd);
}
#endif