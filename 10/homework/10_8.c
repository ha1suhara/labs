#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 100
#define LIMIT 10000

typedef struct {
    double price;
    unsigned circulation;
} Magazine;

int input_magazines(Magazine m[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("Magazine %d (price circulation): ", i + 1);
        if (scanf("%lf %u", &m[i].price, &m[i].circulation) != 2) return 0;
    }
    return 1;
}

int average_price_small(const Magazine m[], int n, double *avg){
    int i, cnt = 0;
    double s = 0;
    for (i = 0; i < n; i++)
        if (m[i].circulation < LIMIT){
            s += m[i].price;
            cnt++;
        }
    if (cnt > 0) *avg = s / cnt;
    return cnt;
}

int main(){
    Magazine m[MAXN];
    int n, cnt;
    double avg;

    printf("N (1..%d) = ", MAXN);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXN){
        printf("Wrong N\n");
        return 0;
    }
    if (!input_magazines(m, n)){
        printf("Input error\n");
        return 0;
    }
    cnt = average_price_small(m, n, &avg);
    if (cnt == 0)
        printf("There are no magazines with circulation less than %d\n", LIMIT);
    else
        printf("Average price of %d magazine(s) with circulation < %d: %.2f\n",
               cnt, LIMIT, avg);
    return 0;
}
