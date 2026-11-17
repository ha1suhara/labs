#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double frac_a(double b, unsigned n){
    double t = b;
    unsigned k;
    for (k = 2; k <= n; k++)
        t = b + 1 / t;
    return t;
}

double frac_b(unsigned n){
    double t = 4.0 * n + 2;
    unsigned k;
    for (k = 1; k <= n; k++)
        t = 4.0 * (n - k) + 2 + 1 / t;
    return t;
}

double frac_v(unsigned n){
    double t = 2;
    int i;
    for (i = 2 * (int)n - 2; i >= 0; i--)
        t = (i % 2 == 0 ? 1 : 2) + 1 / t;
    return t;
}

int main(){
    double b;
    unsigned n;
    printf("Enter b and n (n >= 1): ");
    scanf("%lf %u", &b, &n);
    if (n < 1 || b == 0){
        printf("Wrong input\n");
        return 0;
    }
    printf("a) b_n = %.12f\n", frac_a(b, n));
    printf("b) lambda_n = %.12f  (limit (e+1)/(e-1) = %.12f)\n",
           frac_b(n), (exp(1.0) + 1) / (exp(1.0) - 1));
    printf("v) x_2n = %.12f  (limit (1+sqrt(3))/2 = %.12f)\n",
           frac_v(n), (1 + sqrt(3.0)) / 2);
    return 0;
}
