#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int write_array(const char *fname, const double *a, int n){
    FILE *f = fopen(fname, "wb");
    size_t written;
    if (f == NULL) return 0;
    written = fwrite(a, sizeof(double), n, f);
    fclose(f);
    return written == (size_t)n;
}

int print_file(const char *fname){
    FILE *f = fopen(fname, "rb");
    double x;
    int first = 1;
    if (f == NULL) return 0;
    while (fread(&x, sizeof(double), 1, f) == 1){
        if (!first) printf(", ");
        printf("%g", x);
        first = 0;
    }
    printf("\n");
    fclose(f);
    return 1;
}

int main(){
    int n, i;
    double *a;
    char fname[256];

    printf("n = ");
    if (scanf("%d", &n) != 1 || n < 1){
        printf("Wrong n\n");
        return 1;
    }
    a = (double *)malloc(n * sizeof(double));
    if (a == NULL){
        printf("Not enough memory\n");
        return 1;
    }
    for (i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }
    printf("File name: ");
    scanf("%255s", fname);

    if (!write_array(fname, a, n)) printf("Cannot write file %s\n", fname);
    else if (!print_file(fname)) printf("Cannot read file %s\n", fname);
    free(a);
    return 0;
}
