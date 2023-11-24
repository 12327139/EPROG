#include<stdio.h>
#include<math.h>
#include<assert.h>

double x(int n, double x0, double x1, double (*f)(double)) {
    if (n == 0) return x0;
    if (n == 1) return x1;

    double x_n_minus_1 = x(n-1, x0, x1, f);
    double x_n_minus_2 = x(n-2, x0, x1, f);
    double f_x_n_minus_1 = f(x_n_minus_1);
    
    double zaehler = x_n_minus_2 - x_n_minus_1;
    double nenner = f(x_n_minus_2) - f_x_n_minus_1;
    double bruch = zaehler / nenner;

    return x_n_minus_1 - f_x_n_minus_1 * bruch;
}

double secant(double (*f)(double), double x0, double x1, double tau) {
    assert(tau > 0);

    // Werte
    double x_n = 0;
    double x_n_minus_1 = 0;
    double f_x_n = 0;
    double f_x_n_minus_1 = 0;

    // Bedingungen
    int bedingung_1 = 0;
    int bedingung_2 = 0;
    int bedingung_3 = 0;
    int n = 1;

    do {
        x_n = x(n, x0, x1, f);
        x_n_minus_1 = x(n-1, x0, x1, f);
        f_x_n = f(x_n);
        f_x_n_minus_1 = f(x_n_minus_1);

        bedingung_1 = fabs(f_x_n - f_x_n_minus_1) <= tau;
        bedingung_2 = fabs(f_x_n) <= tau;
        
        if (fabs(x_n) <= tau) {
            bedingung_3 = fabs(x_n - x_n_minus_1) <= tau;
        } else {
            bedingung_3 = fabs(x_n - x_n_minus_1) <= tau * fabs(x_n);
        }

        if (bedingung_1) {
            printf("Warnung: Das numerische Ergebnis ist vermutlich falsch.\n");
        }

        n++;
    } while (!(bedingung_1 || bedingung_2 || bedingung_3));

    return x_n;
}

double f(double x) {
    return 3*x*x - 1;
}

int main() {
    double x0, x1, tau = 0;

    printf("x0=");
    scanf("%lf", &x0);

    printf("x1=");
    scanf("%lf", &x1);

    printf("tau=");
    scanf("%lf", &tau);

    double x_n = secant(f, x0, x1, tau);
    printf("x_n=%lf\n", x_n);
    printf("f(x_n)=%lf\n", f(x_n));

    return 0;
}