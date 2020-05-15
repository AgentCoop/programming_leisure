#include <stdio.h>

include(./incs/common.c)

#define BLACK_COLOR_CODE 'B';
#define MAX_X 10
#define MAX_Y 10

#define PIXEL(x,y) ((pixel *)&pixels[y - 1][x - 1])
#define IS_BLACK_PIXEL(x,y) (PIXEL(x,y)->color == 'B')

#define HAS_RIGHT_NEIGHBOUR(x, y) x < 10 && PIXEL(x + 1, y)->color == 'B'
#define HAS_TOP_NEIGHBOUR(x, y) y < 10 && PIXEL(x, y + 1)->color == 'B'
#define HAS_LEFT_NEIGHBOUR(x, y) x > 1 && PIXEL(x - 1, y)->color == 'B'
#define HAS_BOTTOM_NEIGHBOUR(x, y) y > 1 && PIXEL(x, y - 1)->color == 'B'

#define VISITED(pixel) (pixel->flag & 2)
#define MARK_AS_VISITED(pixel) pixel->flag |= 2
#define DESCRIBED(pixel) pixel->flag & 1
#define SPECIFIED(pixel) pixel->flag & 1

#define MARK_AS_DESCRIBED(pixel) pixel->flag |= 1

typedef struct pixel_t {
    struct pixel_t *right;
    struct pixel_t *top;
    struct pixel_t *left;
    struct pixel_t *bottom;

    unsigned int x, y;
    unsigned int flag;

    char color;
} pixel;


pixel pixels[MAX_Y][MAX_X];

void
describe_pixel(pixel *p)  {
    if (!p) {
        return;
    }
    
    pixel *neighbours[4] = { p->right, p->top, p->left, p->bottom };
    char codes[4] = {'R', 'T', 'L', 'B'};
        
    for (int i = 0; i < 4; i++) {
        pixel *neighbour = neighbours[i];

        if (!neighbour || SPECIFIED(neighbour) || VISITED(neighbour)) {
            continue;
        }

        MARK_AS_DESCRIBED(neighbour);
        printf("%c", codes[i]);
    }

    printf(",\n");
}

void
graph_traversal(pixel *current) {    
    pixel *neighbours[4] = {
        current->right,
        current->top,
        current->left,
        current->bottom
    };

    describe_pixel(current);

    for (int i = 0; i < 4; i++) {
        pixel *neighbour = neighbours[i];

        if (!neighbour || SPECIFIED(neighbour) || VISITED(neighbour)) {
            continue;
        }
        
        describe_pixel(neighbour);
    }
    
    MARK_AS_VISITED(current);

    for (int i = 0; i < 4; i++) {
        if (neighbours[i] && !VISITED(neighbours[i])) {
            graph_traversal(neighbours[i]);
        }
    }
}

int
main(void) {
#if DEBUG
    init_debug();
#endif    
    int pixels_n, x, y;
    int lowest_left_x = MAX_X, lowest_left_y = MAX_Y;

    fscanf(stdin, "%d\n", &pixels_n);
    memset(&pixels, 0, (MAX_X - 1) * (MAX_Y - 1) * sizeof (pixel));

    for (int i = 0; i < pixels_n; i++) {
        fscanf(stdin, "%d %d\n", &x, &y);

        PIXEL(x, y)->color = BLACK_COLOR_CODE;
        PIXEL(x, y)->x = x;
        PIXEL(x, y)->y = y;

        if (x < lowest_left_x && y < lowest_left_y) {
            lowest_left_x = x;
            lowest_left_y = y;
        }
    }

    for (int x = 1; x <= MAX_X; x++) {
        for (int y = 1; y <= MAX_Y; y++) {
            if (!IS_BLACK_PIXEL(x, y)) {
                continue;
            }

            if (HAS_RIGHT_NEIGHBOUR(x, y)) {
                PIXEL(x, y)->right = PIXEL(x + 1, y);
            }

            if (HAS_TOP_NEIGHBOUR(x, y)) {
                PIXEL(x, y)->top = PIXEL(x, y + 1);
            }

            if (HAS_LEFT_NEIGHBOUR(x, y)) {
                PIXEL(x, y)->left = PIXEL(x - 1, y);
            }

            if (HAS_BOTTOM_NEIGHBOUR(x, y)) {
                PIXEL(x, y)->bottom = PIXEL(x, y - 1);
            }
        }
    }

    pixel *start;
    start = PIXEL(lowest_left_x, lowest_left_y);

    printf("%d %d\n", lowest_left_x, lowest_left_y);
    graph_traversal(start);
    printf(".\n");

#if DEBUG
    print_expected();
#endif
    return 0;
}
