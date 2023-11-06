#include<stdio.h>

#define DIM_N 3

int issymmetric(int dim_n, double a[][dim_n]) {
    for (int j = 0; j < dim_n; j++) {
        for (int k = 0; k < dim_n; k++) {
            if (a[j][k] != a[k][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    double A[DIM_N][DIM_N];

    for (int n = 0; n < DIM_N; n++) {
        for (int m = 0; m < DIM_N; m++) {
            printf("A[%d][%d]=", n, m);
            scanf("%lf", &A[n][m]);
        }
    }

    int ergebnis = issymmetric(DIM_N, A);
    printf("issymmetric=%d\n", ergebnis);

    return 0;
}
