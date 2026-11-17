#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int product_a(int x, int y, int z){
    return x * y * z;
}

long long product_b(long long x, long long y, long long z){
    return x * y * z;
}

int main(){
    long long x, y, z;
    long long lim_a = 1LL << 10, lim_b = 1LL << 21;

    printf("Enter three integers separated by commas: ");
    if (scanf("%lld , %lld , %lld", &x, &y, &z) != 3){
        printf("Input error\n");
        return 0;
    }
    if (x > -lim_a && x < lim_a && y > -lim_a && y < lim_a && z > -lim_a && z < lim_a)
        printf("a) |x|<2^10, int product = %d\n", product_a((int)x, (int)y, (int)z));
    else
        printf("a) numbers do not satisfy |x| < 2^10\n");
    if (x > -lim_b && x < lim_b && y > -lim_b && y < lim_b && z > -lim_b && z < lim_b)
        printf("b) |x|<2^21, long long product = %lld\n", product_b(x, y, z));
    else
        printf("b) numbers do not satisfy |x| < 2^21\n");
    return 0;
}
