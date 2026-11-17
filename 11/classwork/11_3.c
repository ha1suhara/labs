#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef int (*Predicate)(int);

int is_even(int x){ return x % 2 == 0; }

int is_power_of_3(int x){
    if (x < 1) return 0;
    while (x % 3 == 0) x /= 3;
    return x == 1;
}

int is_square(int x){
    int r;
    if (x < 0) return 0;
    r = (int)lround(sqrt((double)x));
    return (long long)r * r == x;
}

int is_prime(int x){
    int d;
    if (x < 2) return 0;
    for (d = 2; (long long)d * d <= x; d++)
        if (x % d == 0) return 0;
    return 1;
}

int has_three_divisors(int x){
    int r;
    if (!is_square(x)) return 0;
    r = (int)lround(sqrt((double)x));
    return is_prime(r);
}

int is_palindrome(int x){
    long long rev = 0, t;
    if (x < 0) return 0;
    t = x;
    while (t > 0){ rev = rev * 10 + t % 10; t /= 10; }
    return rev == x;
}

int is_fibonacci(int x){
    long long a = 0, b = 1, t;
    if (x < 0) return 0;
    while (a < x){ t = a + b; a = b; b = t; }
    return a == x;
}

int filter_file(const char *src, const char *dst, Predicate p){
    FILE *f = fopen(src, "rb"), *g;
    int x;
    if (f == NULL) return 0;
    g = fopen(dst, "wb");
    if (g == NULL){ fclose(f); return 0; }
    while (fread(&x, sizeof(int), 1, f) == 1)
        if (p(x)) fwrite(&x, sizeof(int), 1, g);
    fclose(f);
    fclose(g);
    return 1;
}

void print_file(const char *fname){
    FILE *f = fopen(fname, "rb");
    int x;
    printf("%-9s: ", fname);
    if (f == NULL){ printf("cannot open\n"); return; }
    while (fread(&x, sizeof(int), 1, f) == 1) printf("%d ", x);
    printf("\n");
    fclose(f);
}

int main(){
    const char *names[] = { "G_a.bin", "G_b.bin", "G_v.bin", "G_g.bin", "G_d.bin", "G_e.bin" };
    Predicate preds[] = { is_even, is_power_of_3, is_square, has_three_divisors,
                          is_palindrome, is_fibonacci };
    FILE *f = fopen("F.bin", "wb");
    int x, i;

    if (f == NULL){
        printf("Cannot create F.bin\n");
        return 1;
    }
    printf("Enter integers (0 to finish):\n");
    while (1){
        if (scanf("%d", &x) != 1 || x == 0) break;
        fwrite(&x, sizeof(int), 1, f);
    }
    fclose(f);
    print_file("F.bin");

    for (i = 0; i < 6; i++){
        if (!filter_file("F.bin", names[i], preds[i]))
            printf("File error\n");
        else
            print_file(names[i]);
    }
    return 0;
}
