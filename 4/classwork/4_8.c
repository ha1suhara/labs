#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    unsigned long long m, p = 1;
    int k = 0;
    printf("m = ");
    scanf("%llu", &m);
    if (m < 1){
        printf("m must be >= 1\n");
        return 0;
    }
    while (m / p >= 4){
        p *= 4;
        k++;
    }
    printf("k = %d (4^%d = %llu)\n", k, k, p);
    return 0;
}
