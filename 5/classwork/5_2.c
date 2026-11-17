#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef unsigned long long ull;

ull fib(unsigned n){
    ull f0 = 0, f1 = 1, t;
    unsigned i;
    if (n == 0) return 0;
    for (i = 2; i <= n; i++){
        t = f0 + f1;
        f0 = f1;
        f1 = t;
    }
    return f1;
}

unsigned fib_index_not_greater(ull a){
    ull f0 = 0, f1 = 1, t;
    unsigned k = 1;
    if (a == 0) return 0;
    while (f0 + f1 <= a){
        t = f0 + f1;
        f0 = f1;
        f1 = t;
        k++;
    }
    return k;
}

unsigned fib_index_greater(ull a){
    ull f0 = 0, f1 = 1, t;
    unsigned k = 1;
    if (a == 0) return 1;
    while (f1 <= a){
        t = f0 + f1;
        f0 = f1;
        f1 = t;
        k++;
    }
    return k;
}

ull fib_sum_not_greater(ull limit){
    ull f0 = 0, f1 = 1, t, s = 0;
    while (f0 <= limit){
        s += f0;
        t = f0 + f1;
        f0 = f1;
        f1 = t;
    }
    return s;
}

int main(){
    unsigned n;
    ull a;
    printf("n = ");
    scanf("%u", &n);
    if (n > 93) printf("n > 93: F(n) does not fit into unsigned long long\n");
    else printf("a) F(%u) = %llu\n", n, fib(n));

    printf("a (natural) = ");
    scanf("%llu", &a);
    if (a >= fib(93)){
        printf("a is too large\n");
        return 0;
    }
    n = fib_index_not_greater(a);
    printf("b) the largest F(k) <= %llu: k = %u, F(k) = %llu\n", a, n, fib(n));
    n = fib_index_greater(a);
    printf("v) the smallest F(k) > %llu: k = %u, F(k) = %llu\n", a, n, fib(n));
    printf("g) sum of Fibonacci numbers <= 1000: %llu\n", fib_sum_not_greater(1000));
    return 0;
}
