#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double *t1, double *t2){
    double d;
    if (a == 0){
        if (b == 0) return (c == 0) ? -1 : 0;
        *t1 = *t2 = -c / b + 0.0;
        return 1;
    }
    d = b * b - 4 * a * c;
    if (d < 0) return 0;
    if (d == 0){
        *t1 = *t2 = -b / (2 * a) + 0.0;
        return 1;
    }
    *t1 = (-b - sqrt(d)) / (2 * a);
    *t2 = (-b + sqrt(d)) / (2 * a);
    if (*t1 > *t2){ double tmp = *t1; *t1 = *t2; *t2 = tmp; }
    return 2;
}

int main(){
    double a, b, c, t1, t2, roots[4];
    int k, i, cnt = 0;

    printf("Enter coefficients a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("a) %gx^2 + %gx + %g = 0\n", a, b, c);
    k = solve_quadratic(a, b, c, &t1, &t2);
    if (k == -1) printf("   infinitely many solutions (any x)\n");
    else if (k == 0) printf("   no real solutions\n");
    else if (k == 1) printf("   1 solution: x = %g\n", t1);
    else printf("   2 solutions: x1 = %g, x2 = %g\n", t1, t2);

    printf("b) %gx^4 + %gx^2 + %g = 0\n", a, b, c);
    if (k == -1){
        printf("   infinitely many solutions (any x)\n");
        return 0;
    }
    for (i = 0; i < k; i++){
        double t = (i == 0) ? t1 : t2;
        if (t > 0){
            roots[cnt++] = -sqrt(t);
            roots[cnt++] = sqrt(t);
        } else if (t == 0){
            roots[cnt++] = 0;
        }
    }
    if (cnt == 0) printf("   no real solutions\n");
    else {
        printf("   %d solution(s):", cnt);
        for (i = 0; i < cnt; i++) printf(" %g", roots[i]);
        printf("\n");
    }
    return 0;
}
