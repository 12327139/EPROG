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

    if (b_1 == 0 && b_2 == 0) {
        printf("Der Vektor (b_1, b_2) darf nicht (0, 0) sein.");
        return 1;
    }

    double zaehler = a_1 * b_1 + a_2 * b_2;
    double nenner = b_1 * b_1 + b_2 * b_2;

    if (nenner == 0) {
        printf("Division durch null!");
        return 1;
    }

    double bruch = zaehler / nenner;
    
    // (a_1 * b_1 + a_2 * b_2) / (b_1 * b_1 + b_2 * b_2) * b_1
    double orthoA = bruch * b_1;
    
    // (a_1 * b_1 + a_2 * b_2) / (b_1 * b_1 + b_2 * b_2) * b_2
    double orthoB = bruch * b_2;
    
    printf("Orthogonalprojektion von a = %lf\n", orthoA);
    printf("Orthogonalprojektion von b = %lf\n", orthoB);

    return 0;
}