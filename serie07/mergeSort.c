#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

void print_vector(char* name, double* vector, int size) {
    printf("%s: \n", name);
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%g ", *(vector + i));
    }
    printf("%g]\n", *(vector + size - 1));
}

double* merge(double* vector_a, int size_a, double* vector_b, int size_b) {
    int size_c = size_a + size_b;
    double* vector_c = malloc(size_c * sizeof(double));
    assert(vector_c != NULL);

    int counter_a = 0;
    int counter_b = 0;
    for (int i = 0; i < size_c; i++) {
        double value_in_a = *(vector_a + counter_a);
        double value_in_b = *(vector_b + counter_b);

        double smaller_value = 0;

        if (value_in_a < value_in_b && counter_a < size_a) {
            smaller_value = value_in_a;
            counter_a++;
        } else {
            smaller_value = value_in_b;
            counter_b++;
        }

        double* ptr_value_in_c = vector_c + i;
        *ptr_value_in_c = smaller_value;
    }
    return vector_c;
}

void swap(double* a, double* b) {
    double tmp = *b;
    *b = *a;
    *a = tmp;
}

// fuer Vektoren der Laenge 2
void sort_explicitly(double* x) {
    double first_value = *x;
    double second_value = *(x + 1);
    if (second_value > first_value) {
        swap(&first_value, &second_value);
    }
}

void merge_sort(double* x, int n) {
    if (n <= 1) return;
    if (n == 2) return sort_explicitly(x);
    
    int len_first_half = n/2;
    double* first_half = malloc(len_first_half * sizeof(double));
    memcpy(first_half, x, len_first_half);

    int len_second_half = n - len_first_half;
    double* second_half = malloc(len_second_half * sizeof(double));
    memcpy(second_half, x, len_second_half);

    merge_sort(first_half, len_first_half);
    merge_sort(second_half, len_second_half);

    merge(first_half, len_first_half, second_half, len_second_half);
}

int main() {
    int n = 0;

    printf("n=");
    scanf("%d", &n);

    double* x = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        printf("x[%d]=", i);
        scanf("%lf", &x[i]);
    }

    merge_sort(x, n);

    print_vector("Ergebnis", x, n);

    return 0;
}