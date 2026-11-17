#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long steps_to_one(unsigned long long a, long max_steps){
    long steps = 0;
    while (a != 1){
        if (steps >= max_steps) return -1;
        a = (a % 2 == 0) ? a / 2 : 3 * a + 1;
        steps++;
    }
    return steps;
}

int main(){
    unsigned long long n, a;
    unsigned m, best_n = 1;
    long s, best = 0;

    printf("n = ");
    scanf("%llu", &n);
    if (n < 1){
        printf("n must be natural\n");
        return 0;
    }
    a = n;
    printf("%llu", a);
    while (a != 1){
        a = (a % 2 == 0) ? a / 2 : 3 * a + 1;
        printf(" -> %llu", a);
    }
    printf("\nsteps: %ld\n", steps_to_one(n, 100000));

    for (m = 1; m < 1000; m++){
        s = steps_to_one(m, 100000);
        if (s < 0){
            printf("n = %u: did not reach 1\n", m);
            return 0;
        }
        if (s > best){
            best = s;
            best_n = m;
        }
    }
    printf("For every n < 1000 the sequence reaches 1.\n");
    printf("Maximum number of steps: n = %u, %ld steps\n", best_n, best);
    return 0;
}
