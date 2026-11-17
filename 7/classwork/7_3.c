#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define N 10

double sum_greater_than_e(const double a[], int n){
    const double e = exp(1.0);
    double s = 0;
    int i;
    for (i = 0; i < n; i++)
        if (a[i] > e) s += a[i];
    return s;
}

int main(){
    double a[N];
    int i;
    for (i = 0; i < N; i++){
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }
    printf("Sum of elements greater than e: %g\n", sum_greater_than_e(a, N));
    return 0;
}
