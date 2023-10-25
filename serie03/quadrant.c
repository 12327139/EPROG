#include<stdio.h>

void quadrant(double x, double y) {
    if (x == 0 || y == 0) {
        printf("(%lf, %lf) befindet sich auf mindestens einer der Achsen.\n", x, y);
        return;
    }

    int istRechts = x > 0;
    int istOben = y > 0;

    int quadrant = 0;
    if (istOben) {
        if (istRechts) {
            quadrant = 1;
        } else {
            quadrant = 2;
        }
    } else {
        if (istRechts) {
            quadrant = 4;
        } else {
            quadrant = 3;
        }
    }

    printf("(%lf, %lf) befindet sich im %d. Quadrant\n", x, y, quadrant);

}

int main() {
    double x, y = 0;

    printf("x = ");
    scanf("%lf", &x);
    
    printf("y = ");
    scanf("%lf", &y);

    quadrant(x, y);

    return 0;
}