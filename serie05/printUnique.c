#include<stdio.h>

#define DIM_N 3

// Returns the number of times a given number is found in an array
int contains(double x[], int n, double number) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == number) {
            counter++;
        }
    }
    return counter;
}

void printUnique(double x[], int n) {
    for (int i = 0; i < n; i++) {
        if (contains(x, n, x[i]) == 1) {
            printf("%lf\n", x[i]);
        }
    }
}

int main() {
    double x[DIM_N];

    for (int i = 0; i < DIM_N; i++) {
        printf("x[%d]=", i);
        scanf("%lf", &x[i]);
    }

    printUnique(x, DIM_N);

    return 0;
}