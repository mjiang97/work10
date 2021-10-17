#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct shapes {
    int sides; 
    char *s;
    double area; 
    struct shapes *next;
};

void print_shapes(struct shapes *x) {
    printf("shape: %s\n# of sides: %d\narea: %f units squared\n", x->s, x->sides, x->area);
}

void print_list(struct shapes *n) {
    while(n) {
        print_shapes(n);
        printf("\n");
        n = n->next;
    }
}

struct shapes *make_shape(int i, char *c, double d) {
    struct shapes *n = malloc(sizeof(struct shapes));
    n->sides = i;
    n->s = c;
    n->area = d;
    return n;
};

struct shapes * insert_front(struct shapes *front, int sides, char *s, double area) {
    struct shapes *n = make_shape(sides, s, area);
    n->next = front;
    return n;
}
 
struct shapes *free_list(struct shapes *n) {
    struct shapes *front = n;
    while(n) {
        struct shapes *prev = n;
        n = n->next;
        free(prev);
    }
    return front;
}

int main() {
    srand(time(NULL));
    double area = rand() % 100;
    struct shapes *list = make_shape(4, "square", area);
    area = rand() % 100;
    list = insert_front(list, 6, "hexagon", area);
    area = rand() % 100;
    list = insert_front(list, 9, "nonagon", area);
    print_list(list);
    free(list);
    return 0;
}