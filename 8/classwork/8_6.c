#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 100

double diagonal_sum(double a[][MAXN], int n, int m, int k){
    double s = 0;
    int i, j;
    for (i = 0; i < n; i++){
        j = i - k;
        if (j >= 0 && j < m) s += a[i][j];
    }
    return s;
}

int main(){
    static double a[MAXN][MAXN];
    int n, m, k, i, j;

    printf("Enter N and M (< %d): ", MAXN);
    scanf("%d %d", &n, &m);
    if (n < 1 || m < 1 || n >= MAXN || m >= MAXN){
        printf("Wrong size\n");
        return 0;
    }
    for (i = 0; i < n; i++){
        printf("Row %d: ", i);
        for (j = 0; j < m; j++) scanf("%lf", &a[i][j]);
    }
    printf("k = ");
    scanf("%d", &k);
    printf("Sum of A[i][j] with i - j = %d: %g\n", k, diagonal_sum(a, n, m, k));
    return 0;
}
