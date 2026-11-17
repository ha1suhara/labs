#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXN 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    double height;
} Mountain;

void input_mountains(Mountain m[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("Mountain %d (name height): ", i + 1);
        scanf("%49s %lf", m[i].name, &m[i].height);
    }
}

void print_mountains(const Mountain m[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%-20s %8.1f m\n", m[i].name, m[i].height);
}

const char *highest(const Mountain m[], int n){
    int i, best = 0;
    for (i = 1; i < n; i++)
        if (m[i].height > m[best].height) best = i;
    return m[best].name;
}

int find_by_name(const Mountain m[], int n, const char *name){
    int i;
    for (i = 0; i < n; i++)
        if (strcmp(m[i].name, name) == 0) return i;
    return -1;
}

int main(){
    Mountain m[MAXN];
    char name[NAME_LEN];
    int n, k;

    printf("N = ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXN){
        printf("Wrong N\n");
        return 0;
    }
    input_mountains(m, n);
    printf("Mountains:\n");
    print_mountains(m, n);
    printf("The highest: %s\n", highest(m, n));

    printf("Name to search: ");
    scanf("%49s", name);
    k = find_by_name(m, n, name);
    if (k < 0) printf("There is no mountain named %s\n", name);
    else printf("Height of %s: %.1f m\n", name, m[k].height);
    return 0;
}
