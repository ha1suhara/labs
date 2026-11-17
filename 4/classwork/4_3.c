#include <stdio.h>

double poly_a(double x, unsigned n){
    double s = 1;
    unsigned i;
    for (i = 1; i <= n; i++)
        s = s * x + 1;
    return s;
}

double poly_b(double x, double y, unsigned n){
    double s = 1, px = x, py = 1;
    unsigned k;
    for (k = 1; k <= n; k++){
        px = px * px;
        py = py * y;
        s += px * py;
    }
    return s;
}

int main(){
    printf("a) n=3, x=2:      y = %g (expected 15)\n", poly_a(2, 3));
    printf("b) n=4, x=1, y=2: y = %g (expected 31)\n", poly_b(1, 2, 4));
    return 0;
}
