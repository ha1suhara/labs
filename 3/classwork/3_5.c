#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    if (a == b){
        printf("The numbers are equal: %g\n", a);
    } else if (a > b){
        printf("max = %g, min = %g\n", a, b);
    } else {
        printf("max = %g, min = %g\n", b, a);
    }
    return 0;
}
