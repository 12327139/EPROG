#include<stdio.h>
#include<math.h>

#define DIM_N 3

double geometricMean(double x[], int n) {
    double product = 1;
    
    for (int i = 0; i < n; i++) {
        product = product * x[i];
    }

    return pow(product, 1/n);
}

int main() {
    double x[DIM_N];

    for (int i = 0; i < DIM_N; i++) {
        printf("x[%d]=", i);
        scanf("%lf", &x[i]);
    }

    double ergebnis = geometricMean(x, DIM_N);
    printf("ergebnis=%lf", ergebnis);

    return 0;
}