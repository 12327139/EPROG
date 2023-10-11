#include<stdio.h>

int main() {
    int n = 0;

    printf("n = ");
    scanf("%d", &n);
    
    if (n == -2) {
        printf("n darf nicht -2 sein\n");
        return 1;
    }

    double a_n = (double) 1/(n+2);
    printf("a_n = %lf\n", a_n);
    
    return 0;
}