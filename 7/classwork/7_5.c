#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 50

void count_even_odd(const unsigned a[], int n, int *even, int *odd){
    int i;
    *even = *odd = 0;
    for (i = 0; i < n; i++){
        if (a[i] % 2 == 0) (*even)++;
        else (*odd)++;
    }
}

int main(){
    unsigned a[MAXN], x;
    int n = 0, even, odd;

    printf("Enter natural numbers (0 to finish, at most %d):\n", MAXN);
    while (n < MAXN && scanf("%u", &x) == 1 && x != 0)
        a[n++] = x;

    count_even_odd(a, n, &even, &odd);
    printf("Elements: %d, even: %d, odd: %d\n", n, even, odd);
    return 0;
}
