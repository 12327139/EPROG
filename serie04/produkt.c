#include<stdio.h>
#include<assert.h>

int istAusN(int n) {
    return n >= 1;
}

int product(int x, int y) {
    assert(istAusN(x));
    assert(istAusN(y));

    int ergebnis = 0;
    int counter = 0;
    while (++counter <= y) { // y-mal
        ergebnis = ergebnis + x; 
    }
    
    return ergebnis;
}

int main() {
    int x = 0;
    int y = 0;

    printf("x=");
    scanf("%d", &x);

    printf("y=");
    scanf("%d", &y);

    int ergebnis = product(x, y);
    printf("%d*%d=%d\n", x, y, ergebnis);

    return 0;
}