#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double exp_taylor(double x, double eps){
    double term = 1, s = 0;
    int k = 0;
    while (fabs(term) >= eps){
        s += term;
        k++;
        term = term * x / k;
    }
    return s;
}

double phi_taylor(double x, double eps){
    double p = x, s = 0, term = x;
    int k = 0;
    while (fabs(term) >= eps){
        s += term;
        k++;
        p = p * (-x * x) / k;
        term = p / (2 * k + 1);
    }
    return s;
}

int main(){
    double x, eps;
    printf("Enter x and eps: ");
    scanf("%lf %lf", &x, &eps);
    if (eps <= 0){
        printf("eps must be positive\n");
        return 0;
    }
    printf("a) Taylor e^x = %.12f, exp(x) = %.12f\n", exp_taylor(x, eps), exp(x));
    printf("b) Taylor Phi(x) = %.12f, sqrt(pi)/2*erf(x) = %.12f\n",
           phi_taylor(x, eps), sqrt(acos(-1.0)) / 2 * erf(x));
    return 0;
}
