#include <stdio.h>
#include <float.h>

int main(){
    volatile float a = 1.0f, sum;
    do {
        a = a / 2;
        sum = 1.0f + a;
    } while (sum != 1.0f);

    printf("Machine zero for float: a = %e (1 + a == 1)\n", a);
    printf("Previous value 2a = %e is the smallest power of 2 with 1 + 2a != 1\n", 2 * a);
    printf("FLT_EPSILON from <float.h> = %e\n", FLT_EPSILON);
    return 0;
}
