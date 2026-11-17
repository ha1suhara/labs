#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double nested_sin(double x, unsigned n){
    unsigned i;
    for (i = 0; i < n; i++)
        x = sin(x);
    return x;
}

int main(){
    double x;
    unsigned n;
    printf("Enter x and n: ");
    scanf("%lf %u", &x, &n);
    printf("y = %f\n", nested_sin(x, n));
    return 0;
}
