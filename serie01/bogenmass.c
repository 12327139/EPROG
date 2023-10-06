#include<stdio.h>

int main() {
    double winkelInGrad = 0;
    double pi = 3.14;

    printf("Winkel in Grad = ");
    scanf("%lf", &winkelInGrad);

    double winkelInRad = winkelInGrad/180.0 * pi;
    printf("Winkel im Bogenmass = %lf\n", winkelInRad);

    return 0;
}