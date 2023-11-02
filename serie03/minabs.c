#include<stdio.h>

// aus Aufgabe 3
int sgn(double x) {
    return 1 - (2 * (x < 0)); // 1-0 oder 1-2 -> 1 oder -1
}

// aus Aufgabe 3
double dabs(double x) {
    return sgn(x) * x;
}

double minabs(double x, double y) {
    x = dabs(x);
    y = dabs(y);
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    double x, y = 0;

    printf("x = ");
    scanf("%lf", &x);
    
    printf("y = ");
    scanf("%lf", &y);
    
    double kleinererAbsolutbetrag = minabs(x, y);
    printf("%lf ist der kleinere Absolutbetrag\n", kleinererAbsolutbetrag);

    return 0;
}