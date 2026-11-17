#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double segment_length(double x1, double y1, double x2, double y2){
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double triangle_area(double a, double b, double c){
    double p = (a + b + c) / 2;
    double s = p * (p - a) * (p - b) * (p - c);
    return s > 0 ? sqrt(s) : 0;
}

int main(){
    double xa, ya, xb, yb, xc, yc, a, b, c;
    scanf("%lf %lf", &xa, &ya);
    scanf("%lf %lf", &xb, &yb);
    scanf("%lf %lf", &xc, &yc);

    a = segment_length(xb, yb, xc, yc);
    b = segment_length(xa, ya, xc, yc);
    c = segment_length(xa, ya, xb, yb);
    printf("S = %f\n", triangle_area(a, b, c));
    return 0;
}
