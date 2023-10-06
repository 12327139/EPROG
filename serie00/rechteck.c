#include<stdio.h>

int main() {
    double height = 0;
    double width = 0;

    printf("Höhe: ");
    scanf("%lf", &height);

    printf("Breite: ");
    scanf("%lf", &width);

    double area = height * width;
    printf("Fläche: %lf\n", area);

    return 0;
}
