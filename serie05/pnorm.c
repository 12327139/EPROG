#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>

#define DIM_N 4

// x: Vektor aus R^n
// n: Laenge des Vektors
// p: Zahl aus [1, +inf)
double pnorm(double x[], int n, double p) {
    assert(p >= 1);
    assert(n > 0);

    double summe = 0;
    for (int j = 1; j <= n; j++) {
        summe += pow(abs(x[j]), p);
    }
    return pow(summe, 1/p);
}

int main() {
    double x[DIM_N];
    double p = 0;

    for (int i = 0; i < DIM_N; i++) {
        printf("x[%d]=", i);
        scanf("%lf", &x[i]);
    }

    printf("p=");
    scanf("%lf", &p);

    double norm = pnorm(x, DIM_N, p);
    printf("||x||_p = %lf\n", norm);

    return 0;
}

/*
Beobachtung: Bei gleichbleibendem x und groesser werdendem p konvergiert pnorm -> max(x)
*/