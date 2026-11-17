#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double a, h = 0;
    long long n = 0;
    printf("a = ");
    scanf("%lf", &a);
    if (a > 25){
        printf("a is too large (would require ~e^a terms)\n");
        return 0;
    }
    do {
        n++;
        h += 1.0 / n;
    } while (h <= a);
    printf("a) the first partial sum greater than a: %.10f\n", h);
    printf("b) the smallest n: %lld\n", n);
    return 0;
}
