#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day, month, year;
} Date;

int input_date(Date *d){
    printf("Date (dd.mm.yyyy): ");
    return scanf("%d.%d.%d", &d->day, &d->month, &d->year) == 3;
}

void print_date(Date d){
    printf("%02d.%02d.%04d", d.day, d.month, d.year);
}

typedef struct {
    char file;
    int rank;
} ChessField;

int input_field(ChessField *f){
    printf("Chess field (e.g. a5): ");
    if (scanf(" %c%d", &f->file, &f->rank) != 2) return 0;
    if (f->file >= 'A' && f->file <= 'H') f->file = (char)(f->file - 'A' + 'a');
    return f->file >= 'a' && f->file <= 'h' && f->rank >= 1 && f->rank <= 8;
}

void print_field(ChessField f){
    printf("%c%d", f.file, f.rank);
}

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point a, b;
} Rectangle;

int input_point(Point *p){
    return scanf("%lf %lf", &p->x, &p->y) == 2;
}

void print_point(Point p){
    printf("(%g, %g)", p.x, p.y);
}

int input_rectangle(Rectangle *r){
    printf("First vertex (x y): ");
    if (!input_point(&r->a)) return 0;
    printf("Opposite vertex (x y): ");
    return input_point(&r->b);
}

void print_rectangle(Rectangle r){
    printf("Rectangle ");
    print_point(r.a);
    printf(" - ");
    print_point(r.b);
}

typedef struct {
    int degree;
    double coef[];
} Polynomial;

Polynomial *input_polynomial(void){
    int n, i;
    Polynomial *p;
    printf("Degree of the polynomial: ");
    if (scanf("%d", &n) != 1 || n < 0) return NULL;
    p = (Polynomial *)malloc(sizeof(Polynomial) + (n + 1) * sizeof(double));
    if (p == NULL) return NULL;
    p->degree = n;
    for (i = n; i >= 0; i--){
        printf("coefficient of x^%d: ", i);
        scanf("%lf", &p->coef[i]);
    }
    return p;
}

void print_polynomial(const Polynomial *p){
    int i, first = 1;
    for (i = p->degree; i >= 0; i--){
        double c = p->coef[i];
        if (c == 0) continue;
        if (!first) printf(c < 0 ? " - " : " + ");
        else if (c < 0) printf("-");
        printf("%g", c < 0 ? -c : c);
        if (i > 1) printf("x^%d", i);
        else if (i == 1) printf("x");
        first = 0;
    }
    if (first) printf("0");
}

int main(){
    Date d;
    ChessField f;
    Rectangle r;
    Polynomial *p;

    if (input_date(&d)){ printf("Date: "); print_date(d); printf("\n"); }
    else printf("Wrong date\n");

    if (input_field(&f)){ printf("Field: "); print_field(f); printf("\n"); }
    else printf("Wrong field\n");

    if (input_rectangle(&r)){ print_rectangle(r); printf("\n"); }
    else printf("Wrong rectangle\n");

    p = input_polynomial();
    if (p != NULL){
        printf("P(x) = ");
        print_polynomial(p);
        printf("\n");
        free(p);
    } else printf("Wrong polynomial\n");
    return 0;
}
