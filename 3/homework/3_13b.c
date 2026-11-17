#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double a, b, c, D, s, x, y;
    int i;

    printf("Enter a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    D = b - a;
    if (D != 0){
        printf("2 solutions:\n");
        for (i = 0; i < 2; i++){
            s = (i == 0) ? 1 : -1;
            y = (-c - a * s) / D + 0.0;
            x = s - y + 0.0;
            printf("  x = %g, y = %g\n", x, y);
        }
    } else if (a != 0){
        double t = -c / a;
        if (t == 1 || t == -1)
            printf("Infinitely many solutions: all points of the line x + y = %g\n", t);
        else
            printf("No solutions (the line is parallel to x + y = 1 and x + y = -1)\n");
    } else {
        if (c == 0)
            printf("Infinitely many solutions: all points of the lines x + y = 1 and x + y = -1\n");
        else
            printf("No solutions (0 = %g is false)\n", -c);
    }
    return 0;
}
