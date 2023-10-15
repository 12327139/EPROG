#include<stdio.h>
#include<math.h>

int main() {
    double x = 0;
    
    printf("x = ");
    if (!scanf("%lf", &x)) {
        printf("Ungueltige Eingabe");
        return 1;
    }

    int zehntelStelle = abs((int)(x * 10.) % 10);
    int n = (int) x + (zehntelStelle >= 5);
    
    printf("%lf gerundet ist %d\n", x, n);

    return 0;
}