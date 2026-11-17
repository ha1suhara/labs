#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double x, x2, x4, x8;
    printf("x (0..10000) = ");
    scanf("%lf", &x);
    if (x < 0 || x > 10000){
        printf("x must be from 0 to 10000\n");
        return 0;
    }
    x2 = x * x;
    x4 = x2 * x2;
    x8 = x4 * x4;
    printf("x^8 = %25.4f\n", x8);
    return 0;
}
