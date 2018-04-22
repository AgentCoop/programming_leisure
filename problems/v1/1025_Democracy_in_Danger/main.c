#include <stdio.h>
#include <stdlib.h>

include(./incs/common.c)

#define MAX_GROUPS 101
        
int sort_func (const void *, const void *);
int group[MAX_GROUPS];

int
sort_func (const void *a, const void *b)
{
  if (*(int *)a < *(int *)b)
    return -1;
  else if (*(int *)a == *(int *)b)
    return 0;
  else
    return 1;
}

int
main(void) {
#if DEBUG
    init_debug();
#endif

    int groups_num, i, answer = 0;

    fscanf(stdin, "%d", &groups_num);
    
    for (i = 0; i < groups_num; i++)
        fscanf(stdin, "%d", &group[i]);

    // Sort groups by the number of their members
    qsort((void*) group, groups_num, sizeof(int), sort_func);

    for (i = 0; i < (groups_num / 2) + 1; i++)
        answer += (group[i] / 2) + 1; // minimal number of the voters in a group to vote 'for'

    printf("%d\n", answer);

#if DEBUG
    print_expected();
#endif
    return 0;
}
