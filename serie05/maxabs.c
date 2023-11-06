#include<stdio.h>
#include<math.h>

#define DIM_N 5

double maxabs(double x[], int n) {
    double maximum = 0;
    double abs_element = 0;
    for (int i = 0; i < n; i++) {
        abs_element = fabs(x[i]);
        if (abs_element > maximum) {
            maximum = abs_element;
        }
    }
    return maximum;
}   

int main() {
    double x[DIM_N];
    for (int i = 0; i < DIM_N; i++) {
        printf("x[%d]=", i);
        scanf("%lf", &x[i]);
    }

    double ergebnis = maxabs(x, DIM_N);
    printf("maxabs=%lf\n", ergebnis);

    return 0;
}