#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void print_vector(char* name, double* vector, int size) {
    printf("%s: \n", name);
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%g ", *(vector + i));
    }
    printf("%g]\n", *(vector + size - 1));
}

// a und b aufsteigend sortiert
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

int is_sorted_asc(double* vector, int size) {
    for (int i = 1; i < size; i++) {
        double current_value = *(vector+i);
        double previous_value = *(vector+i-1);
        if (current_value < previous_value) return 0;
    }
    return 1;
}

double* read_vector_vorgabe(char* vector_name, int* vector_size) {
    printf("vector %s size = ", vector_name);
    scanf("%d", vector_size);
    
    double* vector = malloc(*vector_size * sizeof(double));
    assert(vector != NULL);
    for (int i = 0; i < *vector_size; i++) {
        printf("%s[%d]=", vector_name, i);
        scanf("%lf", vector+i);
    }
    assert(is_sorted_asc(vector, *vector_size));
    return vector;
}

int main() {
    int m, n = 0; 
    double* a = read_vector_vorgabe("a", &m);
    double* b = read_vector_vorgabe("b", &n);

    double* ergebnis = merge(a, m, b, n);
    print_vector("Ergebnis", ergebnis, m+n);

    free(a);
    a = NULL;

    free(b);
    b = NULL;

    free(ergebnis);
    ergebnis = NULL;

    return 0;
}