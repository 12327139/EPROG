#include <stdio.h>

int pow(int basis, int exponent) {
    if (exponent == 0) return 1;
    return pow(basis, exponent-1) * basis;
}

double P(int n) { 
    int zaehler = 4 * pow(-1, n);
    int nenner = 2 * n + 1;
    double bruch = (double) zaehler / nenner;
    if (n == 0) return bruch;
    return bruch + P(n - 1);
}

int main() {
    int n = 0;

    printf("n = ");
    scanf("%d", &n);

    double pi = P(n);
    printf("pi = %lf\n", pi);

    return 0;
}