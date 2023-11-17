#include<stdio.h> 

#define DIM_N 3

double energy(double x[], int n) {
    double summe = 0;
    for (int j = 0; j < n; j++) {
        summe = summe + (x[j] * x[j]);
    }
    return summe;
}

int main() {
    double x[DIM_N];

    for (int i = 0; i < DIM_N; i++) {
        printf("x[%d]=", i);
        scanf("%lf", &x[i]);
    }

    double ergebnis = energy(x, DIM_N);
    printf("energy=%lf", ergebnis);

    return 0;
}

/*
--------
Laufzeit
--------
Die Funktion energy(double[], int) hat eine lineare Laufzeit.
Es kommt nur eine for-Schleife vor dessen Variable nicht manipuliert wird.

n=10^3: 3 sek
n=10^4: 4 sek
*/