#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 25

void input_int_matrix(int a[][MAXN], int m, int n){
    int i, j;
    for (i = 0; i < m; i++){
        printf("Row %d: ", i);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
}

void input_real_matrix(double a[][MAXN], int m, int n){
    int i, j;
    for (i = 0; i < m; i++){
        printf("Row %d: ", i);
        for (j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);
    }
}

int main(){
    int a[MAXN][MAXN];
    double b[MAXN][MAXN];
    int m, n, i, j;

    printf("Enter m and n (< %d): ", MAXN);
    scanf("%d %d", &m, &n);
    if (m < 1 || n < 1 || m >= MAXN || n >= MAXN){
        printf("Wrong size\n");
        return 0;
    }

    printf("Integer matrix:\n");
    input_int_matrix(a, m, n);
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++) printf("%6d", a[i][j]);
        printf("\n");
    }

    printf("Real matrix:\n");
    input_real_matrix(b, m, n);
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++) printf("%10.3f", b[i][j]);
        printf("\n");
    }
    return 0;
}
