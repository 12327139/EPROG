#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

// e positiv
int q_pow_2(int e) {
    int produkt = 1;
    for (int i = 0; i < e; i++) produkt *= 2;
    return produkt;
}

// e positiv
double q_inv_pow_2(int e) {
    return 1./q_pow_2(e);
}

double float2dec(int M, int* a, int e) {
    assert(M >= 1);
    double summe = 0;
    for (int k = 1; k <= M; k++) {
        summe += a[k-1] * q_inv_pow_2(k);
    }     
    return summe * pow(2, e);
}

int main() {
    int M = 0;
    int* a = NULL;
    int e = 0;
    
    printf("M=");
    scanf("%d", &M);

    a = malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }

    printf("e=");
    scanf("%d", &e);

    double ergebnis = float2dec(M, a, e);
    printf("ergebnis=%lf\n", ergebnis);

    return 0;
}