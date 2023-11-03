#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

// Hilfsfunktion für asserts
int istAusN(int n) {
    return n >= 1;
}

// Fibonacci-Folge
int a(int n) {
    int definitionsbereich = n >= 0 && n < 47; // Ab n=47 Integer-Overflow (unerwartete Ergebnisse)
    assert(definitionsbereich);

    if (n <= 1) {
        return 1;
    }

    int a_n_minus_1 = 1;
    int a_n_minus_2 = 1;
    int a_n = 0;

    int counter = 0;
    while (++counter < n) { // n-1 mal
        a_n = a_n_minus_1 + a_n_minus_2;
        
        // Wir "schiben" den neuen Wert und den Größeren Wert um 1 nach hinten.
        // Uns interessieren nur die letzten 2 Werte um den nächsten zu berechnen.
        a_n_minus_2 = a_n_minus_1;
        a_n_minus_1 = a_n;
    }

    return a_n;
}

// Konvergiert gegen den goldenen Schnitt (1 + sqrt(5))/2
double quotientenfolge(int n) {
    assert(n >= 0);
    return (double) a(n+1) / a(n);
}

// Differenz konviergiert gegen 0
double b(int n) {
    double bruch = (double) a(n) / a(n-1);
    return quotientenfolge(n) - bruch; 
}

int cauchy(int k) {
    assert(istAusN(k));
    double inv_k = 1./k;

    int n = 1;
    while (fabs(b(n)) <= inv_k) {
        ++n;
    }

    return n;
}

int main() {
    int k = 0;

    printf("k = ");
    scanf("%d", &k);
    
    int indexN = cauchy(k);
    printf("Index n = %d\n", indexN);

    return 0;
}
