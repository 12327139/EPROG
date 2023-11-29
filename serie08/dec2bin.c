#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

int kontrolle_summe(int N, int* a, int size) {
    int summe = 0;
    for (int i = 0; i < size; i++) {
        summe += a[i] * pow(2, i);
    }
    return summe == N;
}

int num_digits_of_dec_to_base(int dec, int base) {
    int num_bin_digits = 1;
    while ((dec /= base) >= 1) num_bin_digits++;
    return num_bin_digits;
}

int* dec2bin(int N, int* n) {
    assert(N >= 0 && N < 65535);
    *n = num_digits_of_dec_to_base(N, 2);
    int* bin_digits = malloc(*n * sizeof(int));
    int rest = 0;

    for (int i = 0; i < *n; i++) {
        rest = N % 2;
        bin_digits[i] = rest;
        N /= 2;
    }

    return bin_digits;
}

int main() {
    int N = 0;

    printf("N=");
    scanf("%d", &N);

    int n = 0;
    int* ergebnis = dec2bin(N, &n);
    for (int i = 0; i < n; i++) {
        printf("%d ", ergebnis[n-i-1]);
    }
    printf("\n");

    return 0;
}