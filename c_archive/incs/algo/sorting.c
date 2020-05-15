// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void
merge(void *arr, int el_size, int (*compare_func)(const void *, const void *), int l, int m, int r) {
#define EL(i) (char *) arr + (i) * el_size
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    char L[n1 * el_size], R[n2 * el_size];

    /* Copy data to temp arrays L[] and R[] */
    memcpy(&L, EL(l), n1 * el_size);
    memcpy(&R, EL(m + 1), n2 * el_size);

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (compare_func(&L[i * el_size], &R[j * el_size])) {
            // arr[k] = L[i];
            memcpy(EL(k), &L[i * el_size], el_size);
            i++;
        } else {
            // arr[k] = R[j];
            memcpy(EL(k), &R[j * el_size], el_size);
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        // arr[k] = L[i];
        memcpy(EL(k), &L[i * el_size], el_size);
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        // arr[k] = R[j];
        memcpy(EL(k), &R[j * el_size], el_size);
        j++;
        k++;
    }
#undef EL
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void
merge_sort(void *arr, int el_size, int (*compare_func)(const void *, const void *), int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        merge_sort(arr, el_size, compare_func, l, m);
        merge_sort(arr, el_size, compare_func, m + 1, r);

        merge(arr, el_size, compare_func, l, m, r);
    }
}