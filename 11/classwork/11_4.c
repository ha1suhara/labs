#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define FNAME "rects.bin"
#define TMPNAME "rects.tmp"

typedef struct {
    int number;
    double x1, y1;
    double x2, y2;
} Rect;

double area(Rect r){
    return fabs(r.x2 - r.x1) * fabs(r.y1 - r.y2);
}

int input_rect(Rect *r){
    printf("  number, x1 y1 (upper-left), x2 y2 (lower-right): ");
    return scanf("%d %lf %lf %lf %lf", &r->number, &r->x1, &r->y1, &r->x2, &r->y2) == 5;
}

int create_file(const char *fname){
    FILE *f = fopen(fname, "wb");
    Rect r;
    int n, i;
    if (f == NULL) return 0;
    printf("How many rectangles? ");
    if (scanf("%d", &n) != 1 || n < 0){ fclose(f); return 0; }
    for (i = 0; i < n; i++){
        printf("Rectangle %d:\n", i + 1);
        if (!input_rect(&r)){ fclose(f); return 0; }
        fwrite(&r, sizeof(Rect), 1, f);
    }
    fclose(f);
    return 1;
}

void print_file(const char *fname){
    FILE *f = fopen(fname, "rb");
    Rect r;
    int pos = 0;
    if (f == NULL){ printf("Cannot open %s\n", fname); return; }
    printf("pos | number | (x1, y1) - (x2, y2) | area\n");
    while (fread(&r, sizeof(Rect), 1, f) == 1)
        printf("%3d | %6d | (%g, %g) - (%g, %g) | %g\n",
               pos++, r.number, r.x1, r.y1, r.x2, r.y2, area(r));
    fclose(f);
}

int max_area(const char *fname, int *number, double *s){
    FILE *f = fopen(fname, "rb");
    Rect r;
    int found = 0;
    if (f == NULL) return 0;
    while (fread(&r, sizeof(Rect), 1, f) == 1)
        if (!found || area(r) > *s){
            *s = area(r);
            *number = r.number;
            found = 1;
        }
    fclose(f);
    return found;
}

int delete_by_number(const char *fname, int number){
    FILE *f = fopen(fname, "rb"), *t;
    Rect r;
    int deleted = 0;
    if (f == NULL) return -1;
    t = fopen(TMPNAME, "wb");
    if (t == NULL){ fclose(f); return -1; }
    while (fread(&r, sizeof(Rect), 1, f) == 1){
        if (r.number == number) deleted++;
        else fwrite(&r, sizeof(Rect), 1, t);
    }
    fclose(f);
    fclose(t);
    remove(fname);
    if (rename(TMPNAME, fname) != 0) return -1;
    return deleted;
}

int replace_at(const char *fname, int pos, Rect r){
    FILE *f = fopen(fname, "r+b");
    long size;
    if (f == NULL) return 0;
    fseek(f, 0, SEEK_END);
    size = ftell(f) / (long)sizeof(Rect);
    if (pos < 0 || pos >= size){ fclose(f); return 0; }
    fseek(f, (long)pos * (long)sizeof(Rect), SEEK_SET);
    fwrite(&r, sizeof(Rect), 1, f);
    fclose(f);
    return 1;
}

int main(){
    int choice, number, pos, k;
    double s;
    Rect r;

    if (!create_file(FNAME)){
        printf("Cannot create the file\n");
        return 1;
    }
    do {
        printf("\n1 - show file, 2 - max area, 3 - delete by number, "
               "4 - replace by position, 0 - exit: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice){
        case 1:
            print_file(FNAME);
            break;
        case 2:
            if (max_area(FNAME, &number, &s))
                printf("Rectangle number %d has the largest area %g\n", number, s);
            else printf("The file is empty\n");
            break;
        case 3:
            printf("Number: ");
            scanf("%d", &number);
            k = delete_by_number(FNAME, number);
            if (k < 0) printf("File error\n");
            else printf("Deleted records: %d\n", k);
            break;
        case 4:
            printf("Position (from 0): ");
            scanf("%d", &pos);
            printf("New record:\n");
            if (!input_rect(&r)) { printf("Input error\n"); break; }
            if (replace_at(FNAME, pos, r)) printf("Replaced\n");
            else printf("No such position\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
