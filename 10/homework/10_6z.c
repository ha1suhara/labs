#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    double x, y, z;
} Point3D;

typedef struct {
    Point3D min;
    Point3D max;
} Box;

int input_point(Point3D *p){
    return scanf("%lf %lf %lf", &p->x, &p->y, &p->z) == 3;
}

void print_point(Point3D p){
    printf("(%g, %g, %g)", p.x, p.y, p.z);
}

void swap_if_greater(double *a, double *b){
    if (*a > *b){ double t = *a; *a = *b; *b = t; }
}

int input_box(Box *b){
    printf("First vertex (x y z): ");
    if (!input_point(&b->min)) return 0;
    printf("Opposite vertex (x y z): ");
    if (!input_point(&b->max)) return 0;
    swap_if_greater(&b->min.x, &b->max.x);
    swap_if_greater(&b->min.y, &b->max.y);
    swap_if_greater(&b->min.z, &b->max.z);
    return 1;
}

void print_box(Box b){
    double dx = b.max.x - b.min.x, dy = b.max.y - b.min.y, dz = b.max.z - b.min.z;
    printf("Box ");
    print_point(b.min);
    printf(" - ");
    print_point(b.max);
    printf("\n  edges: %g x %g x %g, volume: %g\n", dx, dy, dz, dx * dy * dz);
}

int main(){
    Box b;
    if (!input_box(&b)){
        printf("Input error\n");
        return 0;
    }
    print_box(b);
    return 0;
}
