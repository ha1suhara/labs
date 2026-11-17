#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    int numerator;
    unsigned int denominator;
} Rational;

unsigned long long gcd(unsigned long long a, unsigned long long b){
    while (b != 0){
        unsigned long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

Rational reduce(Rational r){
    unsigned long long g;
    long long num = r.numerator;
    unsigned long long a = num < 0 ? (unsigned long long)(-num) : (unsigned long long)num;
    if (r.denominator == 0) return r;
    if (num == 0){ r.denominator = 1; return r; }
    g = gcd(a, r.denominator);
    r.numerator = (int)(num / (long long)g);
    r.denominator = (unsigned)(r.denominator / g);
    return r;
}

Rational make_rational(long long num, long long den){
    Rational r;
    unsigned long long g, a, b;
    if (den < 0){ num = -num; den = -den; }
    a = num < 0 ? (unsigned long long)(-num) : (unsigned long long)num;
    b = (unsigned long long)den;
    g = gcd(a, b);
    if (g == 0) g = 1;
    r.numerator = (int)(num / (long long)g);
    r.denominator = (unsigned)(b / g);
    return r;
}

Rational add(Rational a, Rational b){
    return make_rational((long long)a.numerator * b.denominator +
                         (long long)b.numerator * a.denominator,
                         (long long)a.denominator * b.denominator);
}

Rational multiply(Rational a, Rational b){
    return make_rational((long long)a.numerator * b.numerator,
                         (long long)a.denominator * b.denominator);
}

int compare(Rational a, Rational b){
    long long l = (long long)a.numerator * b.denominator;
    long long r = (long long)b.numerator * a.denominator;
    return (l > r) - (l < r);
}

int input_rational(Rational *r){
    int num;
    unsigned den;
    if (scanf("%d/%u", &num, &den) != 2 || den == 0) return 0;
    r->numerator = num;
    r->denominator = den;
    return 1;
}

void print_rational(Rational r){
    printf("%d/%u", r.numerator, r.denominator);
}

int main(){
    Rational a, b;
    int c;
    printf("First number (p/q): ");
    if (!input_rational(&a)){ printf("Wrong number\n"); return 0; }
    printf("Second number (p/q): ");
    if (!input_rational(&b)){ printf("Wrong number\n"); return 0; }

    printf("Reduced: "); print_rational(reduce(a));
    printf(" and "); print_rational(reduce(b)); printf("\n");
    printf("Sum: "); print_rational(add(a, b)); printf("\n");
    printf("Product: "); print_rational(multiply(a, b)); printf("\n");
    c = compare(a, b);
    print_rational(a);
    printf(c < 0 ? " < " : (c > 0 ? " > " : " = "));
    print_rational(b);
    printf("\n");
    return 0;
}
