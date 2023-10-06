#include<stdio.h>

int main() {
    double B, b, h = 0;

    printf("Untere Seite B = ");
    scanf("%lf", &B);
    
    printf("Obere Seite b = ");
    scanf("%lf", &b);
    
    printf("Hoehe h = ");
    scanf("%lf", &h);
    
    double area = 0.5*(B+b)*h;
    printf("Flaeche = %lf\n", area);

    return 0;
}