#include<stdio.h>

int main() {
    double L, x, y = 0;

    printf("Laenge L = ");
    scanf("%lf", &L);

    if (L <= 0) {
        printf("L muss > 0 sein\n");
        return 1;
    }

    printf("x = ");
    scanf("%lf", &x);

    printf("y = ");
    scanf("%lf", &y);

    int imQuadrat = (x > 0 && x < L) && (y > 0 && y < L);
    int ausserhalb = (x < 0 || x > L) && (y < 0 || y > L);

    if (imQuadrat) {
        printf("Der Punkt ist im Quadrat\n");
    } else if (ausserhalb) {
        printf("Der Punkt ist ausserhalb des Quadrates\n");
    } else {
        printf("Der Punkt ist auf dem Rand des Quadrates\n");
    }
    return 0;
}

/*
    int aufDemRand = (x == 0 && ((0 <= y) && (y <= L))) 
                  || (x == L && ((0 <= y) && (y <= L))) 
                  || (y == 0 && ((0 <= x) && (x <= L)))
                  || (y == L && ((0 <= x) && (x <= L)));
*/
    