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

void swap(double* a, double* b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(double* x, int start, int end) {
    int i = start-1;
    for (int j = start; j <= end; j++) {
        if (x[j] < x[end]) {
            swap(&x[++i], &x[j]);
        }
    }
    swap(&x[i+1], &x[end]);
    return i+1;
}

void quick_sort(double* x, int start, int end) {
    if (start < end) {
        int pivot = partition(x, start, end);
        quick_sort(x, start, pivot - 1);
        quick_sort(x, pivot + 1, end);
    }
}

void q_sort(double* x, int n) {
    quick_sort(x, 0, n-1);
}

int main() {
    int n = 0;

    printf("n=");
    scanf("%d", &n);

    double* a = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf("%lf", &a[i]);
    }

    print_vector("Input: ", a, n);
    q_sort(a, n);
    print_vector("Sorted: ", a, n);

    return 0;
}