#include <stdio.h>
#include <stdlib.h>

include(./incs/common.c)
include(./incs/algo/sorting.c)

typedef struct team_t {
    int id;
    int solved_problems_num;
} team;

int
cmp_func(const void *team_a, const void *team_b) {
#define SOLVED(p) ((team *) p)->solved_problems_num
    int solved_a = SOLVED(team_a);
    int solved_b = SOLVED(team_b);
#undef SOLVED
    
    if (solved_a < solved_b)
        return 0;
    else
        return 1;
}

int
main(void) {
#if DEBUG
    init_debug();
#endif    
    int teams_num;
    team *teams;

    fscanf(stdin, "%d\n", &teams_num);
    teams = malloc(teams_num * sizeof (team));

    int id, solved_num;

    for (int i = 0; i < teams_num; i++) {
        fscanf(stdin, "%d %d\n", &id, &solved_num);
        teams[i].id = id;
        teams[i].solved_problems_num = solved_num;
    }

    // Sort in descending order
    merge_sort(teams, sizeof (team), &cmp_func, 0 , teams_num - 1);

    // Output team standings
    for (int i = 0; i < teams_num; i++) {
        printf("%d %d\n", teams[i].id, teams[i].solved_problems_num);
    }    
    
#if DEBUG
    print_expected();
#endif
    return 0;
}
