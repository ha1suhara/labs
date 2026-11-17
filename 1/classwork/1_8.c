#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double a, b;
    printf("Enter the first number: ");
    scanf("%lf", &a);
    printf("Enter the second number: ");
    scanf("%lf", &b);
    printf("a - b = %f\n", a - b);
    printf("a * b = %f\n", a * b);
    return 0;
}
