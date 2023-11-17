#include<stdio.h>
#include<assert.h>

#define DIM_N 3

// Linearer Aufwand
// n=10^2 5s, n=10^4=500s
void minmaxmean(int x[], int dimension, int* min, int* max, int* mean) {
    assert(dimension > 0);
    *min, *max = x[0];
    *mean = 0;

    for (int i = 0; i < dimension; i++) {
        if (x[i] < *min) *min = x[i]; // minimum
        if (x[i] > *max) *max = x[i]; // maximum
        *mean = *mean + x[i]; // mean
    }
    *mean = *mean / dimension;

    return;
}

int main() {
    int x[DIM_N];
    int min, max, mean = 0;

    for (int i = 0; i < DIM_N; i++) {
        printf("x[%d]=", i);
        scanf("%d", &x[i]);
    }

    minmaxmean(x, DIM_N, &min, &max, &mean);
    printf("min=%d\n", min);
    printf("max=%d\n", max);
    printf("mean=%d\n", mean);

    return 0;
}