#include <stdio.h>
#include <math.h>

include(./incs/common.c)

#define MAX_INPUT_SIZE 256 * 1000

int
main(void) {
#if DEBUG
    init_debug();
#endif
    
    double input_integers[MAX_INPUT_SIZE / sizeof(double)];
    int integers_count = 0;
    
    while (fscanf(stdin, "%lf", &input_integers[integers_count]) != EOF)
        integers_count++;
    
    while (integers_count > 0) {
        printf("%0.4lf\n", sqrt(input_integers[integers_count - 1]));
        --integers_count;
    }

#if DEBUG
    print_expected();
#endif
    return 0;
}
