#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    unsigned n, k;
    double a_prev2 = 0, a_prev = 1;
    double b_prev = 0;
    double ak, bk, pow2 = 4, s;

    printf("n = ");
    scanf("%u", &n);
    if (n < 1){
        printf("n must be natural\n");
        return 0;
    }
    s = 2.0 / (0 + 1);
    if (n >= 2) s += 4.0 / (1 + 0);
    for (k = 3; k <= n; k++){
        bk = b_prev + a_prev;
        ak = a_prev / k + a_prev2 * bk;
        pow2 *= 2;
        s += pow2 / (ak + bk);
        a_prev2 = a_prev;
        a_prev = ak;
        b_prev = bk;
    }
    printf("S = %.10g\n", s);
    return 0;
}
