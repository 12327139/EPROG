#include<stdio.h>

int main() {
    double x, y, z = 0;

    printf("x = ");
    if (!scanf("%lf", &x)) {
        printf("Ungültige Eingabe\n");
        return 1;
    }
    
    printf("y = ");
    if (!scanf("%lf", &y)) {
        printf("Ungültige Eingabe\n");
        return 1;
    }
    
    printf("z = ");
    if (!scanf("%lf", &z)) {
        printf("Ungültige Eingabe\n");
        return 1;
    }

    // Bubble-Sort
    {
        double tmp = 0;
        // 1. Iteration
        if (x > y) {
            tmp = y;
            y = x;
            x = tmp;
        }
        if (y > z) {
            tmp = z;
            z = y;
            y = tmp;
        }

        // 2. Iteration
        if (x > y) {
            tmp = y;
            y = x;
            x = tmp;
        }
        if (y > z) {
            tmp = z;
            z = y;
            y = tmp;
        }
    }

    printf("%lf, %lf, %lf\n", z, y, x);
    
    return 0;
}