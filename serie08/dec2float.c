#include <stdio.h>
#include <math.h>

void dec2float(double x, int M, int *digits, int *exponent) {
    *exponent = 0;

    if (x == 0) { //Falls x = 0;
        for (int i = 0; i < M; i++) {
            digits[i] = 0;
        }
        return;
    }

    while (x >= 2.0) { //Exponenten bestimmen
        x = x / 2.0;
        (*exponent)++;
    }
    while (x < 1.0) {
        x *= 2.0;
        (*exponent)--;
    }

    x -= 1.0;   //Normalisieren

    for (int i = 0; i < M; i++) { //Mantisse füllen
        x *= 2.0;
        digits[i] = floor(x);
        x -= digits[i];
    }
}

int main() {
    double x;
    int M = 10;

    printf("Geben Sie die Dezimalzahl x ein: ");
    scanf("%lf", &x);

    int digits[M];
    int exponent;

    dec2float(x, M, digits, &exponent);

    printf("Gleitkommadarstellung von %lf lautet: 1.", x);
    for (int i = 0; i < M; i++) {
        printf("%d", digits[i]);
    }
    printf(" * 2^%d\n", exponent);

    return 0;
}