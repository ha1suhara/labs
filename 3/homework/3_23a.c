#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>

double onestep(double x){
    return x >= 0 ? 1 : 0;
}

double onestep_derivative(double x){
    return x == 0 ? DBL_MAX : 0;
}

int main(){
    double x;
    printf("x = ");
    scanf("%lf", &x);
    printf("onestep(%g)  = %g\n", x, onestep(x));
    printf("onestep'(%g) = %g\n", x, onestep_derivative(x));
    return 0;
}
