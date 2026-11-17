#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define F_NAME "F.bin"
#define G_NAME "G.bin"
#define TMP_NAME "F.tmp"

int create_file(const char *fname){
    FILE *f = fopen(fname, "wb");
    double x;
    int n, i;
    if (f == NULL) return 0;
    printf("How many numbers to write into %s? ", fname);
    if (scanf("%d", &n) != 1 || n < 0){ fclose(f); return 0; }
    for (i = 0; i < n; i++){
        printf("x%d = ", i + 1);
        scanf("%lf", &x);
        fwrite(&x, sizeof(double), 1, f);
    }
    fclose(f);
    return 1;
}

void print_file(const char *fname){
    FILE *f = fopen(fname, "rb");
    double x;
    printf("%s: ", fname);
    if (f == NULL){ printf("cannot open\n"); return; }
    while (fread(&x, sizeof(double), 1, f) == 1) printf("%g ", x);
    printf("\n");
    fclose(f);
}

int build_g(const char *fname, const char *gname, double a){
    FILE *f = fopen(fname, "rb"), *g;
    double x;
    if (f == NULL) return 0;
    g = fopen(gname, "wb");
    if (g == NULL){ fclose(f); return 0; }
    while (fread(&x, sizeof(double), 1, f) == 1)
        if (fabs(x) < a) fwrite(&x, sizeof(double), 1, g);
    fclose(f);
    fclose(g);
    return 1;
}

int remove_small(const char *fname, double a){
    FILE *f = fopen(fname, "rb"), *t;
    double x;
    if (f == NULL) return 0;
    t = fopen(TMP_NAME, "wb");
    if (t == NULL){ fclose(f); return 0; }
    while (fread(&x, sizeof(double), 1, f) == 1)
        if (fabs(x) >= a) fwrite(&x, sizeof(double), 1, t);
    fclose(f);
    fclose(t);
    remove(fname);
    return rename(TMP_NAME, fname) == 0;
}

int main(){
    double a;
    if (!create_file(F_NAME)){
        printf("Cannot create %s\n", F_NAME);
        return 1;
    }
    print_file(F_NAME);
    printf("a (> 0) = ");
    if (scanf("%lf", &a) != 1 || a <= 0){
        printf("Wrong a\n");
        return 1;
    }
    if (!build_g(F_NAME, G_NAME, a) || !remove_small(F_NAME, a)){
        printf("File error\n");
        return 1;
    }
    print_file(G_NAME);
    print_file(F_NAME);
    return 0;
}
