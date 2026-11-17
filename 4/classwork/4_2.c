#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    unsigned n, i;
    unsigned long long f;

    printf("n = ");
    scanf("%u", &n);
    if (n < 1){
        printf("n must be natural\n");
        return 0;
    }

    f = 1;
    printf("%u! = ", n);
    for (i = 1; i <= n; i++){
        f *= i;
        printf(i < n ? "%u*" : "%u", i);
    }
    printf(" = %llu\n", f);

    f = 1;
    printf("%u! = ", n);
    for (i = n; i >= 1; i--){
        f *= i;
        printf(i > 1 ? "%u*" : "%u", i);
    }
    printf(" = %llu\n", f);

    if (n > 20) printf("(note: for n > 20 the value overflows unsigned long long)\n");
    return 0;
}
