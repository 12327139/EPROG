#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void print_vector(char* name, double* vector, int size) {
    printf("%s: \n", name);
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%g ", *(vector + i));
    }
    printf("%g]\n", *(vector + size - 1));
}

double* sample_vector(double* x, int n, int s) {
    double* result = malloc(ceil((double) n/s) * sizeof(double));
    int stelle = 0;
    for (int i = 0; i < n; i += s) {
        result[stelle] = x[i];
        stelle++;
    }
    return result;
}

int main() {
    int n, s = 0;

    printf("n=");
    scanf("%d", &n);

    printf("s=");
    scanf("%d", &s);

    double* x = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        printf("x[%d]=", i);
        scanf("%lf", x+i);
    }

    double* ergebnis = sample_vector(x, n, s);
    print_vector("Ergebnis", ergebnis, ceil((double) n/s));

    free(x);
    x = NULL;
    free(ergebnis);
    ergebnis = NULL;

    return 0;
}