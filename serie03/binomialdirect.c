#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int binomialdirect(int n, int k) {
    int zeahler = factorial(n);
    int nenner = factorial(k) * factorial(n-k);
    return zeahler / nenner;
}

int main() {
    int k, n = 0;
    int untereGrenze = 1;

    printf("k >= %d = ", untereGrenze);
    scanf("%d", &k);
    if (k < untereGrenze) {
        printf("k muss >= %d sein.\n", untereGrenze);
        return 1;
    }

    printf("n > %d = ", k);
    scanf("%d", &n);
    if (n < k) {
        printf("n muss > %d sein.\n", k);
        return 1;
    }

    int ergebnis = binomialdirect(n, k);
    printf("Ergebnis: %d\n", ergebnis);

    return 0;

}