#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAXN 1000

double mean(const double a[], int n){
    double s = 0;
    int i;
    for (i = 0; i < n; i++) s += a[i];
    return s / n;
}

double variance(const double a[], int n){
    double m = mean(a, n), s = 0;
    int i;
    for (i = 0; i < n; i++) s += (a[i] - m) * (a[i] - m);
    return s / n;
}

int main(){
    double a[MAXN], d;
    int n, i;
    printf("N (1..%d) = ", MAXN);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXN){
        printf("Wrong N\n");
        return 0;
    }
    for (i = 0; i < n; i++){
        printf("A[%d] = ", i);
        scanf("%lf", &a[i]);
    }
    d = variance(a, n);
    printf("Mean = %g\n", mean(a, n));
    printf("Variance = %g\n", d);
    printf("Standard deviation = %g\n", sqrt(d));
    return 0;
}
