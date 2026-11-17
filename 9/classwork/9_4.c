#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void free_matrix2d(double **a, int n){
    int i;
    if (a == NULL) return;
    for (i = 0; i < n; i++) free(a[i]);
    free(a);
}

double **zero_matrix2d(int n){
    int i;
    double **a = (double **)malloc(n * sizeof(double *));
    if (a == NULL) return NULL;
    for (i = 0; i < n; i++){
        a[i] = (double *)calloc(n, sizeof(double));
        if (a[i] == NULL){
            free_matrix2d(a, i);
            return NULL;
        }
    }
    return a;
}

double **input_matrix2d(int n){
    int i, j;
    double **a = zero_matrix2d(n);
    if (a == NULL) return NULL;
    for (i = 0; i < n; i++){
        printf("Row %d: ", i);
        for (j = 0; j < n; j++) scanf("%lf", &a[i][j]);
    }
    return a;
}

double **multiply2d(double **a, double **b, int n){
    int i, j, k;
    double **c = zero_matrix2d(n);
    if (c == NULL) return NULL;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

double *zero_matrix1d(int n){
    return (double *)calloc((size_t)n * n, sizeof(double));
}

double *input_matrix1d(int n){
    int i, j;
    double *a = zero_matrix1d(n);
    if (a == NULL) return NULL;
    for (i = 0; i < n; i++){
        printf("Row %d: ", i);
        for (j = 0; j < n; j++) scanf("%lf", &a[i * n + j]);
    }
    return a;
}

void free_matrix1d(double *a){
    free(a);
}

double *multiply1d(const double *a, const double *b, int n){
    int i, j, k;
    double *c = zero_matrix1d(n);
    if (c == NULL) return NULL;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                c[i * n + j] += a[i * n + k] * b[k * n + j];
    return c;
}

int main(){
    int na, nb, i, j;
    double **A = NULL, **B = NULL, **C = NULL;
    double *A1 = NULL, *B1 = NULL, *C1 = NULL;

    printf("=== Variant 1: two-dimensional array ===\n");
    printf("Size of A: ");
    if (scanf("%d", &na) != 1 || na < 1){ printf("Wrong size\n"); return 1; }
    A = input_matrix2d(na);
    printf("Size of B: ");
    if (scanf("%d", &nb) != 1 || nb < 1){ printf("Wrong size\n"); free_matrix2d(A, na); return 1; }
    B = input_matrix2d(nb);
    if (A == NULL || B == NULL) printf("Not enough memory\n");
    else if (na != nb) printf("Different sizes - product is impossible\n");
    else if ((C = multiply2d(A, B, na)) == NULL) printf("Not enough memory\n");
    else {
        printf("A * B =\n");
        for (i = 0; i < na; i++){
            for (j = 0; j < na; j++) printf("%10.3f", C[i][j]);
            printf("\n");
        }
    }
    free_matrix2d(A, na);
    free_matrix2d(B, nb);
    free_matrix2d(C, na);

    printf("=== Variant 2: linear array of size n^2 ===\n");
    printf("Size of A: ");
    if (scanf("%d", &na) != 1 || na < 1){ printf("Wrong size\n"); return 1; }
    A1 = input_matrix1d(na);
    printf("Size of B: ");
    if (scanf("%d", &nb) != 1 || nb < 1){ printf("Wrong size\n"); free_matrix1d(A1); return 1; }
    B1 = input_matrix1d(nb);
    if (A1 == NULL || B1 == NULL) printf("Not enough memory\n");
    else if (na != nb) printf("Different sizes - product is impossible\n");
    else if ((C1 = multiply1d(A1, B1, na)) == NULL) printf("Not enough memory\n");
    else {
        printf("A * B =\n");
        for (i = 0; i < na; i++){
            for (j = 0; j < na; j++) printf("%10.3f", C1[i * na + j]);
            printf("\n");
        }
    }
    free_matrix1d(A1);
    free_matrix1d(B1);
    free_matrix1d(C1);
    return 0;
}
