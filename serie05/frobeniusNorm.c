#include<stdio.h>
#include<assert.h>
#include<math.h>

#define DIM_M 3
#define DIM_N 3
#define DIM_P 3

double frobeniusNorm(int M, int N, int P, double X[][N][P]) {
    assert(M > 0);
    assert(N > 0);
    assert(P > 0);

    double summe = 0;
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            for (int p = 0; p < P; p++) {
                summe = summe + (X[m][n][p] * X[m][n][p]);
            }
        }
    }
    return sqrt(summe);
}

int main() {
    double X[DIM_M][DIM_N][DIM_P];

    for (int m = 0; m < DIM_M; m++) {
        for (int n = 0; n < DIM_N; n++) {
            for (int p = 0; p < DIM_P; p++) {
                printf("X[%d][%d][%d]=", m, n, p);
                scanf("%lf", &X[m][n][p]);
            }
        }
    }

    double ergebnis = frobeniusNorm(DIM_M, DIM_N, DIM_P, X);
    printf("ergebnis=%lf\n", ergebnis);

    return 0;
}