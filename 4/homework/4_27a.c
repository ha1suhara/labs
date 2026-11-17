#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(){
    double eps, s = 0, pi;
    long long n, k;

    printf("eps (>= 1e-9) = ");
    scanf("%lf", &eps);
    if (eps <= 0){
        printf("eps must be positive\n");
        return 0;
    }
    if (eps < 1e-9){
        printf("eps is too small: it would require more than 10^9 terms\n");
        return 0;
    }
    n = (long long)ceil(1 / eps);
    for (k = n; k >= 1; k--)
        s += 1.0 / ((double)k * k);

    pi = sqrt(6 * s);
    printf("pi ~ %.12f (terms: %lld)\n", pi, n);
    printf("acos(-1) = %.12f, error = %e\n", acos(-1.0), fabs(pi - acos(-1.0)));
    return 0;
}
