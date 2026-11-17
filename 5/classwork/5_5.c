#include <stdio.h>

int main(){
    long long x1 = -99, x2 = -99, x3 = -99, xn;
    int n = 3;
    do {
        xn = x3 + x1 + 100;
        x1 = x2;
        x2 = x3;
        x3 = xn;
        n++;
    } while (xn <= 0);
    printf("The smallest positive term: x_%d = %lld\n", n, xn);
    return 0;
}
