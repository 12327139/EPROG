#include<stdio.h>
#include<assert.h>
#include<math.h>

// einseitiger Differenzenquotient
double Phi(double h, double x, double (*f)(double)) {
    assert(h > 0);    
    double zaehler = f(x + h) - f(x);
    return zaehler / h;
}

double h(int n, double h0) {
    return pow(2, -n) * h0;
}

double diff(double (*f)(double), double x, double h0, double tau) {
    assert(tau > 0);
    assert(h0 > 0);

    double Phi_h_n = 0;
    double Phi_h_n_plus_1 = 0;
    int condition = 0;
    int n = 0;
    
    do {
        Phi_h_n = Phi(h(n, h0), x, f);
        Phi_h_n_plus_1 = Phi(h(n+1, h0), x, f);

        double Phi_abstand = fabs(Phi_h_n - Phi_h_n_plus_1);
        if (fabs(Phi_h_n) <= tau) {
            condition = Phi_abstand <= tau;
        } else {
            condition = Phi_abstand <= tau * fabs(Phi_h_n);
        }
        n++;
    } while (!condition);

    return Phi_h_n;
}

double f(double x) {
    return sin(x) + 0.5;
}

int main() {
    double x, h0, tau = 0;

    printf("x=");
    scanf("%lf", &x);

    printf("h0=");
    scanf("%lf", &h0);

    printf("tau=");
    scanf("%lf", &tau);

    double ergebnis = diff(f, x, h0, tau);
    printf("Phi(h_n)=%lf\n", ergebnis);

    return 0;
}