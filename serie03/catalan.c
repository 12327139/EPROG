#include<stdio.h>

// aus Aufgabe 1
int binomialkoeffizient(int n, int k) {
    if (k == 0 || (n == k)) return 1; 
    return binomialkoeffizient(n-1, k) + binomialkoeffizient(n-1, k-1);
}

int catalan(int n) {
    if (n == 1) return 1;
    int zaehler = 2 * (2 * (n-1) + 1);
    int nenner = n + 1;
    double bruch = (double) zaehler / nenner;
    return bruch * catalan(n-1);
}

int catalanMitBinomial(int n) {
    return binomialkoeffizient(2*n, n) - binomialkoeffizient(2*n, n+1);
}

int main() {
    int n = 0;
    
    printf("n = ");
    scanf("%d", &n);
    
    int catalanZahl = catalan(n);
    printf("Rekursiv\tC_%d = %d\n", n, catalanZahl);

    int catalanZahlMitBinomial = catalanMitBinomial(n);
    printf("Binomial\tC_%d = %d\n", n, catalanZahlMitBinomial);

    return 0;
}