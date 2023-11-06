#include<stdio.h>
#include<assert.h>

#define DIM_N 3

double scalarProduct(double x[], double y[], int n) {
    assert(n > 0);

    double summe = 0;
    for (int i = 0; i < n; i++) {
        summe = summe + x[i] * y[i];
    }
    return summe;
}


int main() {
    assert(DIM_N > 0);

    double x[DIM_N], y[DIM_N];

    for (int i = 0; i < DIM_N; i++) {
        printf("x[%d]=", i);
        scanf("%lf", &x[i]);
    }

    for (int i = 0; i < DIM_N; i++) {
        printf("y[%d]=", i);
        scanf("%lf", &y[i]);
    }

    double ergebnis = scalarProduct(x, y, DIM_N);
    printf("ergebnis=%lf\n", ergebnis);

    return 0;
}