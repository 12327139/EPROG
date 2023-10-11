#include<stdio.h>

int main() {
    double B, b, h = 0;

    printf("Untere Seite B = ");
    scanf("%lf", &B);

    if (B <= 0) {
        printf("B muss > 0 sein.\n");
        return 1;
    }
    
    printf("Obere Seite b = ");
    scanf("%lf", &b);
    
    if (b <= 0) {
        printf("b muss > 0 sein.\n");
        return 1;
    }

    printf("Hoehe h = ");
    scanf("%lf", &h);

    if (h <= 0) {
        printf("h muss > 0 sein.\n");
        return 1;
    }

    double area = 0.5*(B+b)*h;
    printf("Flaeche = %lf\n", area);

    return 0;
}