#include <stdio.h>
#include <string.h>
 
include(./incs/common.c)

#define MAX_BANGS 20

int
main(void) {
#if DEBUG
    init_debug();
#endif

    int n, k, answer = 1, t;
    char bangs[MAX_BANGS + 1];

    fscanf(stdin, "%d %s", &n, bangs);
    k = strlen(bangs);
    
    if (n % k)
        for (t = n; t >= n % k; t -= k)
            answer *= t;
    else
        for (t = n; t >= k; t -= k)
            answer *= t;
    
    fprintf(stdout, "%d\n", answer);
#if DEBUG
    print_expected();
#endif
    return 0;
}
