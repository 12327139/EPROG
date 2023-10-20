#include<stdio.h>
#include<stdlib.h>

int main() {
    double x = 0;
    
    printf("x = ");
    if (!scanf("%lf", &x)) {
        printf("Ungueltige Eingabe");
        return 1;
    }

    int zehntelStelle = abs((int)(x * 10.) % 10);
    int rundungswert = (zehntelStelle >= 5) * (x >= 0 ? 1 : -1); // 0, 1 oder -1 
    int n = (int) x + rundungswert;
    
    printf("%lf gerundet ist %d\n", x, n);

    return 0;
}