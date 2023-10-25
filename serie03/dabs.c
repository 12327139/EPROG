#include<stdio.h>

double dabs(double x) {
    return (1 - (2 * (x < 0))) * x;
}

int main() {
    double x = 0;
    
    printf("x = ");
    scanf("%lf", &x);
    
    double xAbs = dabs(x);
    printf("|%lf| = %lf\n", x, xAbs);
    
    return 0;
}