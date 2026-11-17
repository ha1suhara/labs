#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAXN 20

double determinant(double a[][MAXN], int n){
    double det = 1, t;
    int i, j, k, p;
    for (k = 0; k < n; k++){
        p = k;
        for (i = k + 1; i < n; i++)
            if (fabs(a[i][k]) > fabs(a[p][k])) p = i;
        if (fabs(a[p][k]) < 1e-12) return 0;
        if (p != k){
            for (j = 0; j < n; j++){
                t = a[k][j]; a[k][j] = a[p][j]; a[p][j] = t;
            }
            det = -det;
        }
        det *= a[k][k];
        for (i = k + 1; i < n; i++){
            t = a[i][k] / a[k][k];
            for (j = k; j < n; j++)
                a[i][j] -= t * a[k][j];
        }
    }
    return det;
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
    printf("det = %g\n", determinant(a, n));
    return 0;
}
