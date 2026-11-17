#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double hypotenuse(double a, double b){
    return sqrt(a * a + b * b);
}

int main(){
    double a, b;
    printf("Enter legs a and b: ");
    scanf("%lf %lf", &a, &b);
    printf("c = %f\n", hypotenuse(a, b));
    return 0;
}
