#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double arcsin_series(double x, double eps, int *terms){
    double a = x, s = 0;
    int k = 0;
    while (fabs(a) >= eps){
        s += a;
        k++;
        a = a * x * x * (2.0 * k - 1) * (2.0 * k - 1) / ((2.0 * k) * (2.0 * k + 1));
    }
    *terms = k;
    return s;
}

int main(){
    double x, eps, y;
    int terms;
    printf("Enter x (|x| < 1) and eps (> 0): ");
    scanf("%lf %lf", &x, &eps);
    if (fabs(x) >= 1 || eps <= 0){
        printf("Wrong input\n");
        return 0;
    }
    y = arcsin_series(x, eps, &terms);
    printf("Series:  arcsin(%g) = %.12f (terms: %d)\n", x, y, terms);
    printf("math.h:  asin(%g)   = %.12f\n", x, asin(x));
    return 0;
}
