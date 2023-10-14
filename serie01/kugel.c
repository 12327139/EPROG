#include<stdio.h>

int main() {
    double r = 0;
    double pi = 3.14;

    printf("Radius r = ");
    scanf("%lf", &r);

    double volume = 4.0/3.0 * pi * (r*r*r);
    printf("Volumen = %lf\n", volume);

    double surface = 4.0 * pi * (r*r);
    printf("Oberflaeche = %lf\n", surface);

    return 0;
}