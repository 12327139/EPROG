#include<stdio.h>

int main() {
    double r = 0;
    double pi = 3.14;
    double fourThirds = (4.0/3.0);

    printf("Radius r = ");
    scanf("%lf", &r);

    double volume = fourThirds * pi * (r*r*r);
    printf("Volumen = %lf\n", volume);

    double surface = 4 * pi * (r*r);
    printf("Oberflaeche = %lf\n", surface);

    return 0;
}