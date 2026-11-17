#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 51

void reflect_antidiagonal(double a[][MAXN], int N){
    int i, j;
    double t;
    for (i = 0; i < N; i++)
        for (j = 0; i + j < N - 1; j++){
            t = a[i][j];
            a[i][j] = a[N - 1 - j][N - 1 - i];
            a[N - 1 - j][N - 1 - i] = t;
        }
}

void print_matrix(double a[][MAXN], int N){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++) printf("%8.2f", a[i][j]);
        printf("\n");
    }
}

int main(){
    double a[MAXN][MAXN];
    int n, N, i, j;
    printf("n (matrix order is 2n+1, n <= %d): ", (MAXN - 1) / 2);
    if (scanf("%d", &n) != 1 || n < 0 || 2 * n + 1 > MAXN){
        printf("Wrong n\n");
        return 0;
    }
    N = 2 * n + 1;
    for (i = 0; i < N; i++){
        printf("Row %d: ", i);
        for (j = 0; j < N; j++) scanf("%lf", &a[i][j]);
    }
    reflect_antidiagonal(a, N);
    printf("Result:\n");
    print_matrix(a, N);
    return 0;
}
