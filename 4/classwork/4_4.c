#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double x, p = 1, s = 0;
    unsigned n, k;
    printf("Enter n and x: ");
    scanf("%u %lf", &n, &x);
    for (k = 1; k <= n; k++){
        p *= x;
        s += k * p;
    }
    printf("S = %f\n", s);
    return 0;
}
