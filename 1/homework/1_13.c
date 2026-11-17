#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(){
    double x;
    printf("x = ");
    scanf("%lf", &x);
    if (x <= 0){
        printf("The logarithm is defined only for x > 0\n");
        return 0;
    }
    printf("lg(%g) = %.3f\n", x, log10(x));
    return 0;
}
