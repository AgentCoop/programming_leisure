#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

include(./incs/common.c)

#define MAX_STONES_NUM 20

int stones_pile[MAX_STONES_NUM];
int stones_num;

int
piles_weight_diff(int permutation_vec) {
    int curr_idx = 0;
    int w1 = 0, w2 = 0;
    
    while (curr_idx < stones_num) {
        if (permutation_vec & 1) {
            w1 += stones_pile[curr_idx];
        } else {
            w2 += stones_pile[curr_idx];
        }
        
        curr_idx++;
        permutation_vec >>= 1;
    }
    
    return abs(w1 - w2);
}

int
main(void) {
#if DEBUG
    init_debug();
#endif
    int diff, min_diff = INT_MAX;
    
    // Read input
    fscanf(stdin, "%d\n", &stones_num);
    
    for (int i = 0; i < stones_num; i++) {
        fscanf(stdin, "%d ", &stones_pile[i]);
    }
    
    unsigned int max_permutations = (0x1 << (stones_num + 1));
    
    for (int i = 0 ;i < max_permutations; i++) {
        diff = piles_weight_diff(i);
        
        if (diff < min_diff)
            min_diff = diff;
    }
    
    printf("%d\n", min_diff);
#if DEBUG
    print_expected();
#endif
    return 0;
}
