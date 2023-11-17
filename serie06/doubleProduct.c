#include<stdio.h>

#define DIM_N 3

int index2d(int dim, int i, int j) {
    return ((i * dim) + (j + 1)) - 1;
}

double doubleProduct(double a[], double b[], double A[], int n) {
    double summe = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            summe += a[i] * A[index2d(n, i, j)] * b[j];
        }
    }
    return summe;
}

int main() {
    double a[DIM_N], b[DIM_N], A[DIM_N * DIM_N] = {};

    for (int i = 0; i < DIM_N; i++) {
        printf("a[%d]=", i);
        scanf("%lf", &a[i]);
    }

    for (int i = 0; i < DIM_N; i++) {
        printf("b[%d]=", i);
        scanf("%lf", &b[i]);
    }

    for (int i = 0; i < DIM_N; i++) {
        for (int j = 0; j < DIM_N; j++) {
            int index = index2d(DIM_N, i, j);
            printf("A[%d]=", index);
            scanf("%lf", &A[index]);
        }
    }   

    double ergebnis = doubleProduct(a, b, A, DIM_N); 
    printf("ergebnis=%lf\n", ergebnis);

    return 0;
}