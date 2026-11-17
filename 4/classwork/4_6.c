#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(){
    unsigned n, k;
    double a = 0, b;

    printf("n = ");
    scanf("%u", &n);
    if (n < 1){
        printf("n must be natural\n");
        return 0;
    }

    for (k = 1; k <= n; k++)
        a = sqrt(2 + a);
    printf("a) %.10f\n", a);

    b = sqrt(3.0 * n);
    for (k = n - 1; k >= 1; k--)
        b = sqrt(3.0 * k + b);
    printf("b) %.10f\n", b);
    return 0;
}
