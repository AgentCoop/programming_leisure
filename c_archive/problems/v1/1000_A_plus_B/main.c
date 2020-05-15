#include <stdio.h>

include(./incs/common.c)

int
main(void) {
#if DEBUG
    init_debug();
#endif

    int a, b;

    fscanf(stdin, "%d %d\n", &a, &b);

    fprintf(stdout, "%d\n", a + b);

#if DEBUG
    print_expected();
#endif
    return 0;
}