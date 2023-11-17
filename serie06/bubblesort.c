#include<stdio.h>

#define DIM_N 3

void swap(double* x, double* y) {
    double tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(double x[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n-i)-1; j++) {
            if (x[j] > x[j+1]) {
                swap(&x[j], &x[j+1]);
            }
        }
    }
}

int main() {
    double x[DIM_N];

    for (int i = 0; i < DIM_N; i++) {
        printf("x[%d]=", i);
        scanf("%lf", &x[i]);
    }
    
    bubbleSort(x, DIM_N);

    printf("Sorted:\n");
    for (int i = 0; i < DIM_N; i++) {
        printf("%lf ", x[i]);
    }
    printf("\n");

    return 0;
}