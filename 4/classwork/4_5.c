#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned long long double_factorial(unsigned n){
    unsigned long long r = 1;
    unsigned i;
    for (i = n; i > 1; i -= 2)
        r *= i;
    return r;
}

int main(){
    unsigned n;
    printf("n = ");
    scanf("%u", &n);
    printf("%u!! = %llu\n", n, double_factorial(n));
    return 0;
}
