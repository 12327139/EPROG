#include<stdio.h>

int main() {
    int n = 0;

    printf("n = ");
    if (!scanf("%d", &n) || n < 1) {
        printf("Ungültige Eingabe\n");
        return 1;
    }

    int durchZweiTeilbar = n % 2 == 0;
    int durchDreiTeilbar = n % 3 == 0;

    if (durchZweiTeilbar && durchDreiTeilbar) {
        printf("%d ist durch 6 teilbar\n", n);
    } else if (durchZweiTeilbar) {
        printf("%d ist durch 2 teilbar\n", n);
    } else if (durchDreiTeilbar) {
        printf("%d ist durch 3 teilbar\n", n);
    } else {
        printf("%d ist nicht durch 2, 3 oder 6 teilbar\n", n);
    }

    return 0;
}