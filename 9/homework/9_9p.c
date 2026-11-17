#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void free_matrix(double **a, int n){
    int i;
    if (a == NULL) return;
    for (i = 0; i < n; i++) free(a[i]);
    free(a);
}

double **create_matrix(int n, int m){
    int i;
    double **a = (double **)malloc(n * sizeof(double *));
    if (a == NULL) return NULL;
    for (i = 0; i < n; i++){
        a[i] = (double *)malloc(m * sizeof(double));
        if (a[i] == NULL){
            free_matrix(a, i);
            return NULL;
        }
    }
    return a;
}

void fill_matrix(double **a, int n, int m, int random){
    int i, j;
    for (i = 0; i < n; i++){
        if (!random) printf("Row %d: ", i + 1);
        for (j = 0; j < m; j++){
            if (random) a[i][j] = rand() % 7 - 3;
            else scanf("%lf", &a[i][j]);
        }
    }
}

void print_matrix(double **a, int n, int m){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++) printf("%8.2f", a[i][j]);
        printf("\n");
    }
}

int has_zero(const double *row, int m){
    int j;
    for (j = 0; j < m; j++)
        if (row[j] == 0) return 1;
    return 0;
}

int delete_rows_with_zero(double **a, int n, int m){
    int i, k = 0;
    for (i = 0; i < n; i++){
        if (has_zero(a[i], m))
            free(a[i]);
        else
            a[k++] = a[i];
    }
    return k;
}

int main(){
    int n, m, mode;
    double **a;

    srand((unsigned)time(NULL));
    printf("Enter N and M: ");
    if (scanf("%d %d", &n, &m) != 2 || n < 1 || m < 1){
        printf("Wrong size\n");
        return 1;
    }
    a = create_matrix(n, m);
    if (a == NULL){
        printf("Not enough memory\n");
        return 1;
    }
    printf("Fill: 1 - random, 0 - from console: ");
    scanf("%d", &mode);
    fill_matrix(a, n, m, mode == 1);
    printf("Matrix:\n");
    print_matrix(a, n, m);

    n = delete_rows_with_zero(a, n, m);
    if (n == 0)
        printf("All rows contained zeros - the matrix is empty\n");
    else {
        printf("Result (%d x %d):\n", n, m);
        print_matrix(a, n, m);
    }
    free_matrix(a, n);
    return 0;
}
