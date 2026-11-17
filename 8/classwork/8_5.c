#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 20

void transpose(double a[][MAXN], int n){
    int i, j;
    double t;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++){
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
}

void print_matrix(double a[][MAXN], int n){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++) printf("%8.2f", a[i][j]);
        printf("\n");
    }
}

int main(){
    double a[MAXN][MAXN];
    int n, i, j;
    printf("n (< %d) = ", MAXN);
    scanf("%d", &n);
    if (n < 1 || n >= MAXN){
        printf("Wrong size\n");
        return 0;
    }
    for (i = 0; i < n; i++){
        printf("Row %d: ", i);
        for (j = 0; j < n; j++) scanf("%lf", &a[i][j]);
    }
    printf("Original:\n");
    print_matrix(a, n);
    transpose(a, n);
    printf("Transposed:\n");
    print_matrix(a, n);
    return 0;
}
