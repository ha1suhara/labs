#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows, cols;
    double **a;
} Matrix;

void free_matrix(Matrix *m){
    int i;
    if (m->a != NULL){
        for (i = 0; i < m->rows; i++) free(m->a[i]);
        free(m->a);
    }
    m->a = NULL;
    m->rows = m->cols = 0;
}

int alloc_matrix(Matrix *m, int rows, int cols){
    int i;
    m->rows = rows;
    m->cols = cols;
    m->a = (double **)malloc(rows * sizeof(double *));
    if (m->a == NULL){ m->rows = 0; return 0; }
    for (i = 0; i < rows; i++){
        m->a[i] = (double *)calloc(cols, sizeof(double));
        if (m->a[i] == NULL){
            m->rows = i;
            free_matrix(m);
            return 0;
        }
    }
    return 1;
}

int input_matrix(Matrix *m){
    int r, c, i, j;
    m->a = NULL;
    m->rows = m->cols = 0;
    printf("  rows and columns: ");
    if (scanf("%d %d", &r, &c) != 2 || r < 1 || c < 1) return 0;
    if (!alloc_matrix(m, r, c)) return 0;
    for (i = 0; i < r; i++){
        printf("  row %d: ", i);
        for (j = 0; j < c; j++)
            if (scanf("%lf", &m->a[i][j]) != 1){
                free_matrix(m);
                return 0;
            }
    }
    return 1;
}

void print_matrix(const Matrix *m){
    int i, j;
    for (i = 0; i < m->rows; i++){
        for (j = 0; j < m->cols; j++) printf("%10.3f", m->a[i][j]);
        printf("\n");
    }
}

int main(){
    int k, i, r, c, j, entered = 0, same = 1;
    Matrix *arr, sum;

    printf("Number of matrices: ");
    if (scanf("%d", &k) != 1 || k < 1){
        printf("Wrong number\n");
        return 1;
    }
    arr = (Matrix *)calloc(k, sizeof(Matrix));
    if (arr == NULL){
        printf("Not enough memory\n");
        return 1;
    }
    for (i = 0; i < k; i++){
        printf("Matrix %d:\n", i + 1);
        if (!input_matrix(&arr[i])){
            printf("Input error or not enough memory\n");
            break;
        }
        entered++;
    }

    if (entered == k){
        for (i = 1; i < k; i++)
            if (arr[i].rows != arr[0].rows || arr[i].cols != arr[0].cols) same = 0;
        if (!same){
            printf("Matrices have different sizes - the sum is impossible\n");
        } else if (!alloc_matrix(&sum, arr[0].rows, arr[0].cols)){
            printf("Not enough memory\n");
        } else {
            for (i = 0; i < k; i++)
                for (r = 0; r < sum.rows; r++)
                    for (c = 0; c < sum.cols; c++)
                        sum.a[r][c] += arr[i].a[r][c];
            printf("Sum:\n");
            print_matrix(&sum);
            free_matrix(&sum);
        }
    }

    for (j = 0; j < entered; j++) free_matrix(&arr[j]);
    free(arr);
    return 0;
}
