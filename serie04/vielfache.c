#include<stdio.h>
#include<assert.h>

void vielfache(int k, int nmax) {
    assert(k >= 1);
    assert(nmax >= 1);
    int i = 0;
    int produkt = 0;
    while (++i * k < nmax) {
        printf("%d * %d = %d\n", i, k, i*k);
    }
}

int main() {
    int k, nmax = 0;

    printf("k=");
    scanf("%d", &k);

    printf("nmax=");
    scanf("%d", &nmax);

    vielfache(k, nmax);

    return 0;
}