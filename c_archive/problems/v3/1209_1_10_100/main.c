#include <stdio.h>

include(./incs/common.c)

// Maximum number of one digits in the sequence
#define MAX_ONE_DIGITS 65536
        
long int ones_positions[MAX_ONE_DIGITS];

void
fill_ones_positions() {
    unsigned long int seq_length = 0;
    int i = 0, j = 1;
    
    // 1 + 10 + 100
    // 1 -> 2 -> 4
    while (seq_length < MAX_2_31_VALUE) {
        ones_positions[i++] = seq_length + 1;
        seq_length += j;
        j++;
    }
}

// A recursive binary search function
long int
binary_search(unsigned long int x, unsigned int l, unsigned int r) {
   if (r >= l) {
        int mid = l + (r - l) /2;
 
        if (ones_positions[mid] == x)  
            return mid;
 
        if (ones_positions[mid] > x) 
            return binary_search(x, l, mid - 1);
 
        return binary_search(x, mid + 1, r);
   }
 
   // We reach here when element is not present in array
   return -1;
}

int
main(void) {
#if DEBUG
    init_debug();
#endif
    unsigned int n;
    unsigned long int pos;
    
    fscanf(stdin, "%u\n", &n);
    fill_ones_positions();
    
    for (int i = 0; i < n; i++) {
        fscanf(stdin, "%lu\n", &pos);
        
        // The array of the positions of ones has an ascending order, no sorting
        // required for the binary search
        if (binary_search(pos, 0 , MAX_ONE_DIGITS) != -1) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
    
    printf("\n");
   
#if DEBUG
    print_expected();
#endif
    return 0;
}
