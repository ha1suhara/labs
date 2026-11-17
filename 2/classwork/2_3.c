#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double heron(double a, double b, double c){
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(){
    double a, b, c;
    printf("Enter sides a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a + b <= c || a + c <= b || b + c <= a){
        printf("Triangle with such sides does not exist\n");
        return 0;
    }
    printf("S = %f\n", heron(a, b, c));
    return 0;
}
