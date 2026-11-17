#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int N, M, i, j, found = 0;

    printf("Enter N and M: ");
    scanf("%d %d", &N, &M);
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (a[i][j] == M){
                a[i][j] = N;
                found = 1;
            }
    if (!found) printf("Element %d is not in the matrix\n", M);

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
    return 0;
}
