#include <stdio.h>
#include <stdlib.h>
#include <string.h>

include(./incs/common.c)

#define MAX_PATHS 500
#define PATH_MAX_LENGTH 80

struct tree_node_s {
    const char *dir;
    struct tree_node_s *brother;
    struct tree_node_s *child;
};

typedef struct tree_node_s tree_node;

#define DIR(p) (p)->dir
#define BROTHER(p) (p)->brother
#define CHILD(p) (p)->child

tree_node *tree_root[MAX_PATHS];
/* Quantity of trees in the forest. */
unsigned int trees_counter = 0;

tree_node *nodes_heap;
/* Quantity of nodes in the heap. */
unsigned int nodes_counter;

/* Maximum of nodes in the heap. */
#define MAX_NODES 20000

tree_node *root;

#define DIR_BUCKET_TAIL() (char *)(dir_bucket + dir_bucket_used)

char *dir_bucket;
#define DIR_BUCKET_SIZE (40000 + 500)
int dir_bucket_used = 0;

#define PATH_END_MARKER -1
#define PATH_SET_END_MARKER(p)                    \
{                                                 \
  int length = strlen ((p));                      \
  *((char *)((p) + length + 1)) = PATH_END_MARKER;\
}

#define PATH_END(dir) (*(dir) == PATH_END_MARKER)
/* Move pointer to the next directory. */
#define PATH_NEXT_DIR(dir)             \
{                                      \
  int length = strlen ((dir));         \
  (dir) = (char *)((dir) + length + 1);\
}

/* Function prototypes. */
void walk_along_path(tree_node *root, char *dir);

tree_node * new_tree(const char *);

tree_node * tree_add_node(tree_node *, const char *);

tree_node * lookup_roots(const char *dir);
/* Add a directory. */
void dir_bucket_add(const char *name);

void print_disk_tree(tree_node *, unsigned int depth);

int cmp_func(const void *, const void *);

void replace_symbols(char *string, char, char);

int
main(void) {
#if DEBUG
    init_debug();
#endif

    char path[PATH_MAX_LENGTH + 2], *current_dir;
    unsigned int i, n;

    fscanf(stdin, "%d", &n);
    dir_bucket = (char *) malloc(DIR_BUCKET_SIZE);
    nodes_heap = (tree_node *) malloc(MAX_NODES * sizeof (tree_node));

    for (i = 0; i < n; i++) {
        fscanf(stdin, "%s", path);

        PATH_SET_END_MARKER(path);
        /* Split path into directories. */
        replace_symbols(path, '\\', '\0');
        current_dir = path;

        root = lookup_roots(current_dir);
        /* If forest does not contains directories tree then create a new. */
        if (root == NULL)
            root = new_tree(current_dir);

        PATH_NEXT_DIR(current_dir);
        walk_along_path(root, current_dir);
    }

    /* Sort directories in lexicographic order. */
    qsort((tree_node **) tree_root, trees_counter,
            sizeof (tree_root[0]), cmp_func);

    /* Print disk tree. */
    for (i = 0; i < trees_counter; i++)
        print_disk_tree(tree_root[i], 0);

#if DEBUG
    print_expected();
#endif
    return 0;
}

int
cmp_func(const void *n0, const void *n1) {
#define PTR(p) (*(tree_node **) (p))
    return strcmp(DIR(PTR(n0)), DIR(PTR(n1)));
#undef PTR
}

void
print_disk_tree(tree_node *r, unsigned int depth) {
    unsigned int ref_counter, i;
    tree_node * ref_tab[MAX_PATHS];

    for (i = 0; i < depth; i++)
        fprintf(stdout, " ");
    fprintf(stdout, "%s\n", DIR(r));

    r = CHILD(r);
    if (r == NULL)
        return;

    for (ref_counter = 0; BROTHER(r); ref_counter++) {
        ref_tab[ref_counter] = r;
        r = BROTHER(r);
    }
    ref_tab[ref_counter++] = r;

    qsort(ref_tab, ref_counter, sizeof (tree_node *), cmp_func);

    for (i = 0; i < ref_counter; i++)
        print_disk_tree(ref_tab[i], depth + 1);
}

void
dir_bucket_add(const char *dir) {
    int length = strlen(dir);
    /* Copy new directory into the bucket. */
    strcpy(DIR_BUCKET_TAIL(), dir);
    dir_bucket_used = dir_bucket_used + length + 1;
}

tree_node *
new_tree(const char *dir) {
    tree_root[trees_counter] = &nodes_heap[nodes_counter++];
    DIR(tree_root[trees_counter]) = DIR_BUCKET_TAIL();
    CHILD(tree_root[trees_counter]) = NULL;
    dir_bucket_add(dir);
    return tree_root[trees_counter++];
}

tree_node *
tree_add_node(tree_node *p, const char *dir) {
    tree_node *new_node;

    new_node = &nodes_heap[nodes_counter++];

    /* Find youngest brother. */
    if (CHILD(p)) {
        p = CHILD(p);
        while (BROTHER(p))
            p = BROTHER(p);
        BROTHER(p) = new_node;
    } else
        CHILD(p) = new_node;

    CHILD(new_node) = BROTHER(new_node) = NULL;
    DIR(new_node) = DIR_BUCKET_TAIL();
    dir_bucket_add(dir);
    return new_node;
}

tree_node *
lookup_roots(const char *dir) {
    unsigned int i;

    for (i = 0; i < trees_counter; i++)
        if (!strcmp(DIR(tree_root[i]), dir))
            return tree_root[i];
    return NULL;
}

void
walk_along_path(tree_node *parent, char *dir) {
    tree_node *p;

    if (PATH_END(dir))
        return;

    if (CHILD(parent) == NULL) {
        p = tree_add_node(parent, dir);
        PATH_NEXT_DIR(dir);
        walk_along_path(p, dir);
    } else {
        p = CHILD(parent);
        do
            if (!strcmp(DIR(p), dir)) {
                PATH_NEXT_DIR(dir);
                walk_along_path(p, dir);
                return;
            } while ((p = BROTHER(p)) != NULL);
        p = tree_add_node(parent, dir);
        PATH_NEXT_DIR(dir);
        walk_along_path(p, dir);
    }
}

void
replace_symbols(char *string, char a, char b) {
    int i, length = strlen(string);

    for (i = 0; i < length; i++)
        if (string[i] == a)
            string[i] = b;
}