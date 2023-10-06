#include<stdio.h>

int main() {
    double a_1, a_2, b_1, b_2 = 0;
    
    printf("a_1 = ");
    scanf("%lf", &a_1);

    printf("a_2 = ");
    scanf("%lf", &a_2);
    
    printf("b_1 = ");
    scanf("%lf", &b_1);
    
    printf("b_2 = ");
    scanf("%lf", &b_2);

    double bruch = (a_1*b_1 + a_2*b_2)/(b_1*b_1 + b_2*b_2);
    double orthoA = bruch * b_1;
    double orthoB = bruch * b_2;

    printf("Orthogonalprojektion von a = %lf\n", orthoA);
    printf("Orthogonalprojektion von b = %lf\n", orthoB);

    return 0;
}