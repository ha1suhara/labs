#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

uint16_t mul8(uint8_t a, uint8_t b){
    return (uint16_t)((uint16_t)a * b);
}

int main(){
    unsigned a, b;
    printf("Enter two numbers from 0 to 255: ");
    scanf("%u %u", &a, &b);
    if (a > 255 || b > 255){
        printf("Numbers must be 8-bit (0..255)\n");
        return 0;
    }
    printf("%u * %u = %u\n", a, b, (unsigned)mul8((uint8_t)a, (uint8_t)b));
    return 0;
}
