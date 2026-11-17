#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TOYS "toys.bin"
#define FOUND "found.bin"
#define MISSING "missing.bin"

typedef struct {
    char name[30];
    double price;
    int min_age;
    int max_age;
} Toy;

void print_toy(const Toy *t){
    printf("  %-15s %8.2f UAH, ages %d-%d\n", t->name, t->price, t->min_age, t->max_age);
}

int create_toys_file(const char *fname){
    FILE *f = fopen(fname, "wb");
    Toy t;
    int n, i;
    if (f == NULL) return 0;
    printf("How many toys? ");
    if (scanf("%d", &n) != 1 || n < 0){ fclose(f); return 0; }
    for (i = 0; i < n; i++){
        memset(&t, 0, sizeof t);
        printf("Toy %d (name price min_age max_age): ", i + 1);
        if (scanf("%29s %lf %d %d", t.name, &t.price, &t.min_age, &t.max_age) != 4){
            fclose(f);
            return 0;
        }
        fwrite(&t, sizeof(Toy), 1, f);
    }
    fclose(f);
    return 1;
}

void print_file(const char *fname){
    FILE *f = fopen(fname, "rb");
    Toy t;
    printf("%s:\n", fname);
    if (f == NULL){ printf("  (no file)\n"); return; }
    while (fread(&t, sizeof(Toy), 1, f) == 1) print_toy(&t);
    fclose(f);
}

int find_constructor(const char *toys, double Y, int x){
    FILE *f = fopen(toys, "rb"), *out;
    Toy t;
    int found = 0;
    if (f == NULL) return -1;
    out = fopen(FOUND, "wb");
    if (out == NULL){ fclose(f); return -1; }

    while (fread(&t, sizeof(Toy), 1, f) == 1)
        if (strcmp(t.name, "constructor") == 0 && fabs(t.price - Y) < 0.005 &&
            t.min_age <= x && t.max_age >= 12){
            fwrite(&t, sizeof(Toy), 1, out);
            if (found == 0) printf("Found:\n");
            print_toy(&t);
            found++;
        }
    fclose(f);
    fclose(out);

    if (found == 0){
        FILE *m = fopen(MISSING, "ab");
        if (m == NULL) return -1;
        memset(&t, 0, sizeof t);
        strcpy(t.name, "constructor");
        t.price = Y;
        t.min_age = x;
        t.max_age = 12;
        fwrite(&t, sizeof(Toy), 1, m);
        fclose(m);
        printf("No such constructor. The record about its absence is added to %s\n", MISSING);
    }
    return found;
}

int main(){
    double Y;
    int x;
    if (!create_toys_file(TOYS)){
        printf("Cannot create %s\n", TOYS);
        return 1;
    }
    print_file(TOYS);
    printf("Price Y and age x: ");
    if (scanf("%lf %d", &Y, &x) != 2 || x < 0 || x > 12){
        printf("Wrong input (0 <= x <= 12)\n");
        return 1;
    }
    if (find_constructor(TOYS, Y, x) < 0){
        printf("File error\n");
        return 1;
    }
    print_file(FOUND);
    print_file(MISSING);
    return 0;
}
