#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double C, F;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &C);
    F = 9 * C / 5 + 32;
    printf("F=%g\n", F);
    return 0;
}
