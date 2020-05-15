#include <stdio.h>
#include <stdlib.h>

include(./incs/common.c)

typedef struct point_coords_s {
    double x;
    double y;
} point_coords;

typedef struct cockroach_s {
    struct point_coords_s coord;
    double distance;
    uint_16 num;
} cockroach;

int
cmpfunc (const void * a, const void * b) {
   return ( ((cockroach* )a)->distance - ((cockroach* )b)->distance );
}

int
main(void) {
#if DEBUG
    init_debug();
#endif
    uint_16 cockroaches_num, sweet_pieces_num;

    // Scan cockroaches coordinates
    fscanf(stdin, "%u\n", &cockroaches_num);
    cockroach *cockroaches = malloc(sizeof (cockroach) * cockroaches_num);

    for (uint_16 i = 0; i < cockroaches_num; i++) {
        fscanf(stdin, "%lf %lf\n", &cockroaches[i].coord.x, &cockroaches[i].coord.y);
        cockroaches[i].num = i + 1;
    }

    // Scan sweet pieces coordinates
    fscanf(stdin, "%u\n", &sweet_pieces_num);

    if (!sweet_pieces_num) {
        return 0;
    }

    point_coords *sweet_pieces = malloc(sizeof (point_coords) * sweet_pieces_num);

    for (uint_16 i = 0; i < sweet_pieces_num; i++) {
        fscanf(stdin, "%lf %lf\n", &sweet_pieces[i].x, &sweet_pieces[i].y);
    }
    
    point_coords *sweet_piece;
    
    // Loop over sweet pieces coordinates and find the closest cockroaches
    for (uint_16 i = 0; i < sweet_pieces_num; i++) {
        sweet_piece = &sweet_pieces[i];
        
        for (uint_16 j = 0; j < cockroaches_num; j++) {
            cockroach *cockroach = &cockroaches[j];
            
            double dist = sqrt(powf(sweet_piece->x - cockroach->coord.x, 2) +
                powf(sweet_piece->y - cockroach->coord.y, 2));
            
            // Store calculated distance
            cockroach->distance = dist;
        }

        // Sort in ascending order the calculated distances to the current sweet piece
        qsort(cockroaches, cockroaches_num, sizeof(cockroach), cmpfunc);
        
        uint_16 k = 0;
        double d1, d2;
        
        do {
            printf("%u ", cockroaches[k++].num);
            d1 = cockroaches[k - 1].distance;
            d2 = cockroaches[k].distance;
        } while (k < cockroaches_num &&  d1 == d2);
        
        printf("\n");
    }

#if DEBUG
    print_expected();
#endif
    return 0;
}
