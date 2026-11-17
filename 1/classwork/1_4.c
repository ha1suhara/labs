#include <stdio.h>

int main(){
    double gamma = 6.673e-11;
    double m1 = 5.97e24;
    double m2 = 7.35e22;
    double r = 3.844e8;
    double F = gamma * m1 * m2 / (r * r);
    printf("F=%e\n", F);
    return 0;
}
