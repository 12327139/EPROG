#include<stdio.h>
#include<assert.h>
#include<math.h>

int istAusN(int n) {
    return n >= 1;
}

double folgenglied(int n) {
    assert(istAusN(n));
    double zaehler = pow(-1, n);
    double nenner = sqrt(n) + 2;
    return zaehler/nenner;
}

int main() {
    int n = 0;

    printf("n=");
    scanf("%d", &n);

    double a_n = folgenglied(n);
    printf("%lf\n", a_n);

    return 0;
}

/*
-------------------
Wie wurde getestet?
-------------------

*/