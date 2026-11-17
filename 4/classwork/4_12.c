#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int n, k, sign = 1;
    unsigned long long exact = 1;
    double approx = 1;

    printf("n (0 <= n < 25) = ");
    scanf("%d", &n);
    if (n < 0 || n >= 25){
        printf("Wrong n\n");
        return 0;
    }
    for (k = 1; k <= n; k++){
        sign = -sign;
        exact = exact * k + sign;
        approx = approx * k + sign;
    }
    if (n <= 20)
        printf("!%d = %llu\n", n, exact);
    else
        printf("!%d = %.0f (double, approximately)\n", n, approx);
    return 0;
}
