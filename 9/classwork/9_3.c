#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double *input_vector(int n){
    int i;
    double *v = (double *)malloc(n * sizeof(double));
    if (v == NULL) return NULL;
    for (i = 0; i < n; i++){
        printf("  [%d] = ", i);
        scanf("%lf", &v[i]);
    }
    return v;
}

void free_vector(double **v){
    free(*v);
    *v = NULL;
}

double *vector_difference(const double *a, const double *b, int n){
    int i;
    double *c = (double *)malloc(n * sizeof(double));
    if (c == NULL) return NULL;
    for (i = 0; i < n; i++) c[i] = a[i] - b[i];
    return c;
}

int main(){
    int n1, n2, i;
    double *a = NULL, *b = NULL, *c = NULL;

    printf("Dimension of a: ");
    if (scanf("%d", &n1) != 1 || n1 < 1){ printf("Wrong dimension\n"); return 1; }
    a = input_vector(n1);
    if (a == NULL){ printf("Not enough memory\n"); return 1; }

    printf("Dimension of b: ");
    if (scanf("%d", &n2) != 1 || n2 < 1){ printf("Wrong dimension\n"); free_vector(&a); return 1; }
    b = input_vector(n2);
    if (b == NULL){ printf("Not enough memory\n"); free_vector(&a); return 1; }

    if (n1 != n2){
        printf("Vectors have different dimensions - difference is impossible\n");
    } else {
        c = vector_difference(a, b, n1);
        if (c == NULL) printf("Not enough memory\n");
        else {
            printf("a - b = (");
            for (i = 0; i < n1; i++) printf(i < n1 - 1 ? "%g, " : "%g", c[i]);
            printf(")\n");
        }
    }
    free_vector(&a);
    free_vector(&b);
    free_vector(&c);
    return 0;
}
