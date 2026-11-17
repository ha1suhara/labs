#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100

int input_array(int **arr){
    int x, n = 0;
    *arr = (int *)malloc(MAXN * sizeof(int));
    if (*arr == NULL) return -1;
    printf("Enter integers (0 to finish, at most %d):\n", MAXN);
    while (n < MAXN && scanf("%d", &x) == 1 && x != 0)
        (*arr)[n++] = x;
    return n;
}

int is_square(int x){
    long long r;
    if (x < 0) return 0;
    r = (long long)llround(sqrt((double)x));
    return r * r == x;
}

int is_cube(int x){
    long long r = (long long)llround(cbrt((double)x));
    return r * r * r == x;
}

int main(){
    int *a = NULL;
    int n, i, squares = 0, cubes = 0;

    n = input_array(&a);
    if (n < 0){
        printf("Not enough memory\n");
        return 1;
    }
    for (i = 0; i < n; i++){
        if (is_square(a[i])) squares++;
        if (is_cube(a[i])) cubes++;
    }
    printf("Elements: %d, perfect squares: %d, perfect cubes: %d\n", n, squares, cubes);
    free(a);
    return 0;
}
