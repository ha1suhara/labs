#include <stdio.h>

int main(){
    int a[] = { 5, 112, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    for (i = n - 1; i >= 0; i--)
        printf(i > 0 ? "%d," : "%d\n", a[i]);
    return 0;
}
