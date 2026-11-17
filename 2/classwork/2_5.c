#include <stdio.h>

double Rosenbrock2d(double x, double y){
    double t = x * x - y;
    return 100 * t * t + (x - 1) * (x - 1);
}

int main(){
    printf("Rosenbrock2d(1, 1)  = %f (expected 0)\n", Rosenbrock2d(1, 1));
    printf("Rosenbrock2d(0, 0)  = %f (expected 1)\n", Rosenbrock2d(0, 0));
    printf("Rosenbrock2d(2, 1)  = %f (expected 901)\n", Rosenbrock2d(2, 1));
    printf("Rosenbrock2d(-1.5, 0.5) = %f\n", Rosenbrock2d(-1.5, 0.5));
    return 0;
}
