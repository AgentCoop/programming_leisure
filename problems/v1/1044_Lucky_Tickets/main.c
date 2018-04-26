#include <stdio.h>

include(./incs/common.c)

/**
 * Returns total count of n-digits numbers with the given sum k 
 */
int
N(int n, long int k) {
    if (k < 0 || k > 9 * n) {
        return 0;
    }
    
    if (k == 0) {
        return 1;
    }
    
    if (n == 1) {
        return (k >= 0 && k <= 9 ) ? 1 : 0;
    }
    
    int total_count = 0;
    
    for (int l = k - 9; l <= k; l++) {
        total_count += N(n - 1, l);
    }
    
    return total_count;
}

/**
 * n is the number of digits in a ticket
 */
unsigned long int
lucky_tickets_num(int n) {
    int half_n = n / 2;
    
    return N(n, 9 * half_n);    
}

int
main(void) {
#if DEBUG
    init_debug();
#endif
    int num_digits  ;
    
    fscanf(stdin, "%d\n", &num_digits);
 
    printf("%lu\n", lucky_tickets_num(num_digits));

#if DEBUG
    print_expected();
#endif
    return 0;
}
