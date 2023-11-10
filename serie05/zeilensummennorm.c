#include<stdio.h>
#include<math.h>

#define DIM_N 3
#define DIM_M 3

double zeilensummennorm(double matrix[][DIM_M], int dim_n) {
    double summe = 0;
    double max = 0;
    for (int n = 0; n < dim_n; n++) { // fuer jede zeile
        for (int m = 0; m < DIM_M; m++) { // fuer jede spalte
            summe = summe + fabs(matrix[n][m]); 
        }
        if (summe > max) {
            max = summe;
        }
        summe = 0;
    }
    return max;
}

int main() {
    double A[DIM_N][DIM_M];

    for (int n = 0; n < DIM_N; n++) {
        for (int m = 0; m < DIM_M; m++) {
            printf("A[%d][%d]=", n, m);
            scanf("%lf", &A[n][m]);
        }
    }

    double norm = zeilensummennorm(A, DIM_N);
    printf("%lf\n", norm);

    return 0;
}