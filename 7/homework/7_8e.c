#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 1000

int is_prime(unsigned long long x){
    unsigned long long d;
    if (x < 2) return 0;
    if (x % 2 == 0) return x == 2;
    for (d = 3; d * d <= x; d += 2)
        if (x % d == 0) return 0;
    return 1;
}

int count_primes(const unsigned long long a[], int n){
    int i, cnt = 0;
    for (i = 0; i < n; i++)
        if (is_prime(a[i])) cnt++;
    return cnt;
}

int main(){
    unsigned long long a[MAXN];
    int n, i;
    printf("N (1..%d) = ", MAXN);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXN){
        printf("Wrong N\n");
        return 0;
    }
    for (i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%llu", &a[i]);
    }
    printf("Prime numbers in the array: %d\n", count_primes(a, n));
    return 0;
}
