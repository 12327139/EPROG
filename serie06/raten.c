#include<stdio.h>
#include<math.h>
#include<time.h>

#define DIM_M 10

double a_n(int N){
    double summe = 0;
    for (int n = 0; n < N; n++) {
        double zaehler = 1.;
        double nenner = (n + 1) * (n + 1);
        double bruch = zaehler / nenner;
        summe += bruch;
    }
    return summe;
}

double b_n(int N) {
    double summe = 0;
    for (int n = 0; n < N; n++) {
        for (int k = 0; k < n; k++) {
            double zaehler = 1.;
            double klammer1 = (k + 1) * (k + 1);
            double klammer2 = (n - k + 1) * (n - k + 1); 
            double nenner = klammer1 * klammer2;
            double bruch = zaehler / nenner;
            summe += bruch;
        }
    }
    return summe;
}

// Zeit zur Berechnung von a_n
double f(int N_i) {
    clock_t start = clock();
    a_n(N_i);
    clock_t runtime = clock() - start;
    return (double) runtime / CLOCKS_PER_SEC;
}

void alpha(int N[], int M, double raten[]) {
    double zaehler, nenner = 0;
    for (int i = 1; i < M; i++) {
        zaehler = log(f(N[i])) - log(f(N[i-1]));
        nenner = log(N[i]) - log(N[i-1]);
        raten[i] = zaehler / nenner;
    }
}

void printTabelle(int N[], double raten[], int dim) {
    printf("____ Raten ____\n");
    printf("i\tN\tRate\t\n");
    printf("-------------------\n");
    for (int i = 0; i < dim; i++) {
        printf("%d\t%d\t%lf\n", i, N[i], raten[i]);
    }
}

int main() {
    int N[DIM_M];
    double raten[DIM_M];

    for (int i = 0; i < DIM_M; i++) {
        printf("N[%d]=", i);
        scanf("%d", &N[i]);
    }

    alpha(N, DIM_M, raten);
    printTabelle(N, raten, DIM_M);

    return 0;
}