#include <stdio.h>

include(./incs/common.c)

int
main (void)
{
#if DEBUG
    init_debug();
#endif
    
    int a, b;
    
    fscanf(stdin, "%d %d\n", &a, &b);
    
    fprintf(stdout, "%d", a + b);
    
    return 0;
}