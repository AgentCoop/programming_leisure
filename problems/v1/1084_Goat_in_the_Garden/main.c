#include <stdio.h>
#include <math.h>

include(./incs/common.c)

int
main(void) {
    double side, radius;
    double A, B, alpha;
    double S_seg, S_tri, diff;
    double S_result;

#if DEBUG
    init_debug();
#endif

    fscanf(stdin, "%lf %lf", &side, &radius);

    if (radius <= (side / 2))
        S_result = M_PI * radius * radius;
    else if (radius < sqrt(side * side / 2)) {
        /* Calculation of the sum of the squares of the kitchen-garden corners which
         * cannot be reached by the goat.
         */
        A = (side / 2) - sqrt(radius * radius - ((side * side) / 4));
        B = sqrt(2 * A * A);
        alpha = 2 * asin((B / 2) / radius);

        S_seg = radius * radius * alpha / 2;
        S_tri = radius * radius * sin(alpha) / 2;
        diff = S_seg - S_tri;
        S_result = side * side - ((A * A / 2) - diff) * 4;
    } else
        /* All will be eaten by the goat. */
        S_result = side * side;

    fprintf(stdout, "%.3f\n", S_result);
    
#if DEBUG
    print_expected();
#endif

    return 0;
}