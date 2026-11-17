#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 20

void input_matrix(double a[][MAXN], int m, int n){
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
}

void print_matrix(double a[][MAXN], int m, int n){
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++)
            printf("%10.3f", a[i][j]);
        printf("\n");
    }
}

int main(){
    double a[MAXN][MAXN];
    int m, n;
    printf("Enter m and n (< %d): ", MAXN);
    scanf("%d %d", &m, &n);
    if (m < 1 || n < 1 || m >= MAXN || n >= MAXN){
        printf("Wrong size\n");
        return 0;
    }
    input_matrix(a, m, n);
    printf("Matrix:\n");
    print_matrix(a, m, n);
    return 0;
}
