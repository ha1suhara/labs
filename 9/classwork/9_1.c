#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i;
    double *a, s = 0;

    printf("n = ");
    if (scanf("%d", &n) != 1 || n < 1){
        printf("Wrong n\n");
        return 1;
    }
    a = (double *)malloc(n * sizeof(double));
    if (a == NULL){
        printf("Not enough memory\n");
        return 1;
    }
    for (i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }
    for (i = 0; i < n; i++)
        s += a[i] * a[i];
    printf("Sum of squares = %g\n", s);

    free(a);
    return 0;
}
