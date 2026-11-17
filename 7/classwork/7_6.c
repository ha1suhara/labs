#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 20

void input_vector(double v[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("  [%d] = ", i);
        scanf("%lf", &v[i]);
    }
}

void print_vector(const double v[], int n){
    int i;
    printf("(");
    for (i = 0; i < n; i++)
        printf(i < n - 1 ? "%g, " : "%g", v[i]);
    printf(")\n");
}

void add_vectors(const double a[], const double b[], double res[], int n){
    int i;
    for (i = 0; i < n; i++)
        res[i] = a[i] + b[i];
}

double dot_product(const double a[], const double b[], int n){
    double s = 0;
    int i;
    for (i = 0; i < n; i++)
        s += a[i] * b[i];
    return s;
}

int main(){
    double a[MAXN], b[MAXN], c[MAXN];
    int n;

    printf("Dimension n (1..%d): ", MAXN - 1);
    scanf("%d", &n);
    if (n < 1 || n >= MAXN){
        printf("Wrong dimension\n");
        return 0;
    }
    printf("Vector a:\n");
    input_vector(a, n);
    printf("Vector b:\n");
    input_vector(b, n);

    add_vectors(a, b, c, n);
    printf("a + b = ");
    print_vector(c, n);
    printf("(a, b) = %g\n", dot_product(a, b, n));
    return 0;
}
