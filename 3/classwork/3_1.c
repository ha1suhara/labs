#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    unsigned n, d1, d2, d3;
    printf("Enter a three-digit number: ");
    scanf("%u", &n);
    if (n < 100 || n > 999){
        printf("The number is not three-digit\n");
        return 0;
    }
    d1 = n % 10;
    d2 = n / 10 % 10;
    d3 = n / 100;

    printf("a) units = %u, tens = %u, hundreds = %u\n", d1, d2, d3);
    printf("b) sum of digits = %u\n", d1 + d2 + d3);
    printf("v) reversed = %u\n", d1 * 100 + d2 * 10 + d3);
    return 0;
}
