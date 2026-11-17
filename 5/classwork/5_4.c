#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    unsigned n, i;
    double pa = 1, pb = 1, inv_fact = 1, pow2 = 1, sign = -1;

    printf("n = ");
    scanf("%u", &n);
    for (i = 1; i <= n; i++){
        inv_fact /= i;
        pa *= 1 + inv_fact;

        pow2 *= 2;
        sign = -sign;
        pb *= 1 + sign * (double)i * i / pow2;
    }
    printf("a) P = %.10f\n", pa);
    printf("b) P = %.10f\n", pb);
    return 0;
}
