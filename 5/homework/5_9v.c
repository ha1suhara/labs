#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double v_element(int n){
    double v3 = 0, v2 = 0, v1 = 1.5, v = 0;
    int i;
    if (n == 0 || n == 1) return 0;
    if (n == 2) return 1.5;
    for (i = 3; i <= n; i++){
        v = (i - 2.0) / ((i - 3.0) * (i - 3.0) + 1) * v1 - v2 * v3 + 1;
        v3 = v2;
        v2 = v1;
        v1 = v;
    }
    return v;
}

int main(){
    int n, i;
    printf("n = ");
    scanf("%d", &n);
    if (n < 0){
        printf("n must be >= 0\n");
        return 0;
    }
    printf("v_%d = %.10g\n", n, v_element(n));
    printf("First elements:");
    for (i = 0; i <= 6; i++) printf(" %g", v_element(i));
    printf("\n");
    return 0;
}
