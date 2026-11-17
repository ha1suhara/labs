#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 5

void input_array(int a[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

int max_element(const int a[], int n){
    int i, m = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > m) m = a[i];
    return m;
}

int main(){
    int a[N];
    input_array(a, N);
    printf("Max = %d\n", max_element(a, N));
    return 0;
}
