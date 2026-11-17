#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 5

int main(){
    int a[N] = { 7, -3, 12, 0, 5 };
    double x;
    int i, count = 0;

    printf("Array: ");
    for (i = 0; i < N; i++) printf("%d ", a[i]);
    printf("\nEnter a real number: ");
    scanf("%lf", &x);

    for (i = 0; i < N; i++)
        if (a[i] < x) count++;
    printf("Elements less than %g: %d\n", x, count);
    return 0;
}
