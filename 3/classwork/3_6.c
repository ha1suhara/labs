#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c, mx, mn;
    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    mx = a;
    if (fabs(b) > fabs(mx)) mx = b;
    if (fabs(c) > fabs(mx)) mx = c;

    mn = a;
    if (fabs(b) < fabs(mn)) mn = b;
    if (fabs(c) < fabs(mn)) mn = c;

    printf("Largest by absolute value:  %g\n", mx);
    printf("Smallest by absolute value: %g\n", mn);
    return 0;
}
