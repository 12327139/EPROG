#include<stdio.h>

int main() {
    double x = 0;
    
    printf("x = ");
    if (!scanf("%lf", &x)) {
        printf("Ungueltige Eingabe");
        return 1;
    }

    int zehntelStelle = (int)(x * 10.) % 10;

    int n = (int) x;
    if (x >= 0 && zehntelStelle >= 5) {
        n += 1;
    } 
    if (x < 0 && zehntelStelle <= -5) {
        n -= 1;
    }
    
    printf("%lf gerundet ist %d\n", x, n);

    return 0;
}