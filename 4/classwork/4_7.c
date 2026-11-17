#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(){
    double x, term = 1, y = 1;
    int n, k;
    printf("Enter x (|x| < 1) and n (n >= 0): ");
    scanf("%lf %d", &x, &n);
    if (fabs(x) >= 1 || n < 0){
        printf("Wrong input\n");
        return 0;
    }
    for (k = 1; k <= n; k++){
        term = term * x / k;
        y += term;
    }
    printf("y = %.10f\n", y);
    printf("exp(x) = %.10f (for comparison)\n", exp(x));
    return 0;
}
