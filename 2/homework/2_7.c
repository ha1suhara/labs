#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double ellipse_area(double a, double b){
    const double PI = acos(-1.0);
    return PI * a * b;
}

int main(){
    double a, b;
    printf("Enter semi-axes a and b: ");
    scanf("%lf %lf", &a, &b);
    printf("S = %f\n", ellipse_area(a, b));
    return 0;
}
