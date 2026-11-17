#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double poly(double x){
    double t = 2 * x;
    double t2 = t * t;
    double a = t2 + 1;
    double b = a + t;
    return a * b - t2;
}

int main(){
    double x;
    printf("x = ");
    scanf("%lf", &x);
    printf("y = %f\n", poly(x));
    printf("check: %f\n", 16 * x * x * x * x + 8 * x * x * x + 4 * x * x + 2 * x + 1);
    return 0;
}
