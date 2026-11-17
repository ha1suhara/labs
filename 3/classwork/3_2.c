#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    unsigned n, a, b, c;
    printf("Enter a three-digit number: ");
    scanf("%u", &n);
    if (n < 100 || n > 999){
        printf("The number is not three-digit\n");
        return 0;
    }
    a = n / 100;
    b = n / 10 % 10;
    c = n % 10;
    if (a == b || b == c || a == c){
        printf("Digits are not all different\n");
        return 0;
    }
    printf("%u %u %u %u %u %u\n",
           a * 100 + b * 10 + c, a * 100 + c * 10 + b,
           b * 100 + a * 10 + c, b * 100 + c * 10 + a,
           c * 100 + a * 10 + b, c * 100 + b * 10 + a);
    return 0;
}
