#include<stdio.h>

int main() {
    double m, q = 0;

    printf("y=mx+q\n");
    
    printf("m = ");
    scanf("%lf", &m);
    
    if (m == 0) {
        printf("m darf nicht 0 sein\n");
        return 1;
    }

    printf("q = ");
    scanf("%lf", &q);
    
    double x_0 = -q/m;
    printf("x_0 = %lf\n", x_0);
    printf("Koordinaten: x=%lf, y=0\n", x_0);

    return 0;
}