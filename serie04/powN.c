#include<stdio.h>
#include<stdlib.h>

double powN(double x, int n) {
    // Sonderfälle
    if (x == 0 && n > 0) return 0;
    if (x != 0 && n == 0) return 1;
    if (x == 0 && n <= 0) return 0.0/0.0;

    // Entspricht (((x*x)*x)*x)*x...
    int counter = 0;
    double produkt = 1;
    while (++counter < abs(n)) { // n-1 mal 
        printf("x");
        produkt = produkt * x; 
    }

    // Sonderfall
    if (n < 0) return 1./produkt;
    
    return produkt;
}


int main() {
    double x = 0;
    int n = 0;

    printf("x=");
    scanf("%lf", &x);

    printf("n=");
    scanf("%d", &n);

    double ergebnis = powN(x, n);
    printf("%lf\n", ergebnis);

    return 0;
}