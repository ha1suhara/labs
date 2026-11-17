#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <math.h>

int main(){
    float f1 = 1e-4f, f2 = 24.33E5f, f3 = (float)acos(-1.0), f4 = (float)exp(1.0),
          f5 = (float)sqrt(5.0), f6 = (float)log(100.0);
    double d1 = 1e-4, d2 = 24.33E5, d3 = acos(-1.0), d4 = exp(1.0),
           d5 = sqrt(5.0), d6 = log(100.0);
    long double l1 = 1e-4L, l2 = 24.33E5L, l3 = acosl(-1.0L), l4 = expl(1.0L),
                l5 = sqrtl(5.0L), l6 = logl(100.0L);

    printf("float:       %.2f %.2f %.2f %.2f %.2f %.2f\n", f1, f2, f3, f4, f5, f6);
    printf("double:      %.2f %.2f %.2f %.2f %.2f %.2f\n", d1, d2, d3, d4, d5, d6);
    printf("long double: %.2Lf %.2Lf %.2Lf %.2Lf %.2Lf %.2Lf\n", l1, l2, l3, l4, l5, l6);
    return 0;
}
