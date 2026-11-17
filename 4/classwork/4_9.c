#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    unsigned long long n, p = 1;
    int r = 0;
    printf("n = ");
    scanf("%llu", &n);
    if (n >= (1ULL << 63)){
        printf("2^64 (does not fit into unsigned long long)\n");
        return 0;
    }
    while (p <= n){
        p *= 2;
        r++;
    }
    printf("2^%d = %llu\n", r, p);
    return 0;
}
