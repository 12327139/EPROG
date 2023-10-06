#include<stdio.h>

int main() {
    double pricePerMinuteInEuros = 0.27;
    double g = 0; // Guthaben in Euro

    printf("Guthaben g in Euro = ");
    scanf("%lf", &g);

    double callTimeInMinutes = pricePerMinuteInEuros * g;
    printf("Mit %lf Euro kann man %lf Minuten telefonieren\n", g, callTimeInMinutes);

    return 0;
}