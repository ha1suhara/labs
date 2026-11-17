#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(){
    double x, sum = 0, log_sum = 0;
    long long a;
    int i = 0, count = 0, negatives = 0;

    printf("Part 1: enter real numbers, 0 to finish\n");
    do {
        printf("a[%d]= ", i);
        if (scanf("%lf", &x) != 1) return 0;
        sum += x;
        i++;
    } while (x != 0);
    printf("Sum = %g\n", sum);

    printf("Part 2: enter nonzero integers, 0 to finish\n");
    sum = 0;
    i = 0;
    while (1){
        printf("a[%d]= ", i);
        if (scanf("%lld", &a) != 1 || a == 0) break;
        sum += (double)a;
        log_sum += log(fabs((double)a));
        if (a < 0) negatives++;
        count++;
        i++;
    }
    if (count == 0){
        printf("The sequence is empty\n");
        return 0;
    }
    printf("Arithmetic mean = %g\n", sum / count);
    if (negatives % 2 == 1 && count % 2 == 0)
        printf("Geometric mean is not defined (negative product, even root)\n");
    else {
        double g = exp(log_sum / count);
        if (negatives % 2 == 1) g = -g;
        printf("Geometric mean = %g\n", g);
    }
    return 0;
}
