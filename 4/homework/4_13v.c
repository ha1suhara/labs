#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double sin_powers_sum(double x, unsigned n){
    double s = sin(x), r = 1;
    unsigned i;
    for (i = 1; i <= n; i++)
        r = r * s + 1;
    return r;
}

int main(){
    double x;
    unsigned n;
    printf("Enter n and x: ");
    scanf("%u %lf", &n, &x);
    printf("S = %.10f\n", sin_powers_sum(x, n));
    return 0;
}
