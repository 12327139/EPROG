#include<stdio.h>
#include<assert.h>

#define DIM_N 3

double max(double vector[], int n) {
    assert(n > 0);
    
    double maximum = vector[0];
    for (int i = 1; i < n; i++) {
        if (vector[i] > maximum) {
            maximum = vector[i];
        }
    }
    return maximum;
}

int maxcompare(double a[], double b[], int n) {
    assert(n > 0);

    int max_a = max(a, n);
    int max_b = max(b, n);

    if (max_a != max_b) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && a[i] == max_a) {
            count++;
        }
    }

    return count;
}

int main() {
    assert(DIM_N >= 1);

    double a[DIM_N], b[DIM_N];

    for (int i = 0; i < DIM_N; i++) {
        printf("a[%d]=", i);
        scanf("%lf", &a[i]);
    }

    for (int i = 0; i < DIM_N; i++) {
        printf("b[%d]=", i);
        scanf("%lf", &b[i]);
    }

    int ergebnis = maxcompare(a, b, DIM_N);
    printf("ergebnis=%d\n", ergebnis);

    return 0;
}