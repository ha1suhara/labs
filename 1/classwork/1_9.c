#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double a, b, am, hm;
    printf("Enter two numbers in one line: ");
    scanf("%lf %lf", &a, &b);
    am = (a + b) / 2;
    hm = 2 * a * b / (a + b);
    printf("Arithmetic mean: %e  %f\n", am, am);
    printf("Harmonic mean:   %e  %f\n", hm, hm);
    return 0;
}
