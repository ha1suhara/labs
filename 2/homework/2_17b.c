#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double bent(double x){
    return (sqrt(x * x + 1) - 1) / 2 + x;
}

double bent_derivative(double x){
    return x / (2 * sqrt(x * x + 1)) + 1;
}

int main(){
    double x;
    printf("bent(0) = %f (expected 0)\n", bent(0));
    printf("bent'(0) = %f (expected 1)\n", bent_derivative(0));

    printf("x = ");
    scanf("%lf", &x);
    printf("bent(%g) = %f\n", x, bent(x));
    printf("bent'(%g) = %f\n", x, bent_derivative(x));
    return 0;
}
