#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double x, x2, x3, x4, x6, x8, x12, x16, x24, x32;
    printf("x = ");
    scanf("%lf", &x);

    x2 = x * x;
    x4 = x2 * x2;
    printf("a) x^4  = %g\n", x4);

    x2 = x * x;
    x3 = x2 * x;
    x6 = x3 * x3;
    printf("b) x^6  = %g\n", x6);

    x2 = x * x;
    x4 = x2 * x2;
    x8 = x4 * x4;
    printf("v) x^9  = %g\n", x8 * x);

    x2 = x * x;
    x3 = x2 * x;
    x6 = x3 * x3;
    x12 = x6 * x6;
    printf("g) x^15 = %g\n", x12 * x3);

    x2 = x * x;
    x4 = x2 * x2;
    x8 = x4 * x4;
    x16 = x8 * x8;
    x24 = x16 * x8;
    printf("d) x^28 = %g\n", x24 * x4);

    x2 = x * x;
    x4 = x2 * x2;
    x8 = x4 * x4;
    x16 = x8 * x8;
    x32 = x16 * x16;
    printf("e) x^64 = %g\n", x32 * x32);
    return 0;
}
