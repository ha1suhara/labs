#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double m[3][3] = { {1.0, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int i, j;
    double a;

    printf("Enter i, j (0..2) and a: ");
    if (scanf("%d %d %lf", &i, &j, &a) != 3){
        printf("Input error\n");
        return 0;
    }
    if (i < 0 || i > 2 || j < 0 || j > 2){
        printf("Indices are out of range\n");
        return 0;
    }
    m[i][j] = a;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++)
            printf("%8.2f", m[i][j]);
        printf("\n");
    }
    return 0;
}
