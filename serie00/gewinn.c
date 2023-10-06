#include<stdio.h>

int main() {
    double x = 0; // in Euro, Gewinn bei einem Spiel
    int n = 0; // Anzahl von Freunden
    double y = 0; // x Euro aufgeteilt auf n Freunde
    
    printf("Gewinn in Euro: ");
    scanf("%lf", &x); 

    printf("Anzahl Freunde: ");
    scanf("%d", &n);

    y = x / n; // Achtung! Division durch 0

    printf("Jede Person bekommt %lf Euro.\n", y);
    
    return 0;
}