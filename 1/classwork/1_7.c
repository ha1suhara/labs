#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(){
    double x, ip, fp;
    long long t, fl, ce, rn;

    printf("x = ");
    scanf("%lf", &x);

    t = (long long)x;
    fl = t;
    if (x < fl) fl = fl - 1;
    ce = t;
    if (x > ce) ce = ce + 1;
    rn = (x >= 0) ? (long long)(x + 0.5) : (long long)(x - 0.5);

    printf("Without math.h:\n");
    printf("  integer part    = %lld\n", t);
    printf("  fractional part = %f\n", x - t);
    printf("  ceil            = %lld\n", ce);
    printf("  floor           = %lld\n", fl);
    printf("  round           = %lld\n", rn);

    fp = modf(x, &ip);
    printf("With math.h:\n");
    printf("  integer part    = %.0f\n", ip);
    printf("  fractional part = %f\n", fp);
    printf("  ceil            = %.0f\n", ceil(x));
    printf("  floor           = %.0f\n", floor(x));
    printf("  round           = %.0f\n", round(x));
    return 0;
}
