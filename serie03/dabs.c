#include<stdio.h>

int sgn(double x) {
    return 1 - (2 * (x < 0)); // 1-0 oder 1-2 -> 1 oder -1
}

double dabs(double x) {
    return sgn(x) * x;
}

int main() {
    double x = 0;
    
    printf("x = ");
    scanf("%lf", &x);
    
    double xAbs = dabs(x);
    printf("|%lf| = %lf\n", x, xAbs);
    
    return 0;
}