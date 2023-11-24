#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_vector(char* name, double* vector, int size) {
    printf("%s: \n", name);
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%g ", *(vector + i));
    }
    printf("%g]\n", *(vector + size - 1));
}

double* append_vector(double* x, int n, double* y, int m) {
    double* result = malloc((n+m) * sizeof(double));
    memcpy(result, x, n * sizeof(double));
    memcpy(result + n, y, m * sizeof(double));
    return result;
}

int main() {
    int n, m = 0;

    printf("n=");
    scanf("%d", &n);

    double* x = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        printf("x[%d]=", i);
        scanf("%lf", &x[i]);
    }

    printf("m=");
    scanf("%d", &m);

    double* y = malloc(m * sizeof(double));
    for (int i = 0; i < n; i++) {
        printf("y[%d]=", i);
        scanf("%lf", &y[i]);
    }

    double* appended = append_vector(x, n, y, m);
    print_vector("appended", appended, n+m);

    return 0;
}