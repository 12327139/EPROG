#include<stdio.h>

void square(double* x) {
    double* y = x;
    *x = *x * *y;
}

int main() {
    double x = 2.1;
    square(&x);
    printf("x^2=%lf\n", x);
    return 0;
}