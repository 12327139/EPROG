#include<stdio.h>

// Laufzeit: O(n)
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

int main() {
    int N = 0;

    printf("N=");
    scanf("%d", &N);

    double erg_a_n = a_n(N) * a_n(N);
    double erg_b_n = b_n(N);

    printf("erg_a_n = %lf\n", erg_a_n);
    printf("erg_b_n = %lf\n", erg_b_n);

    return 0;
}