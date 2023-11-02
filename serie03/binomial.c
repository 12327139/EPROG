#include<stdio.h>

int binomial(int n, int k) {
    if (k == 0 || (n == k)) return 1; 
    return binomial(n-1, k) + binomial(n-1, k-1);
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

    int ergebnis = binomial(n, k);
    printf("Ergebnis: %d\n", ergebnis);

    return 0;
}