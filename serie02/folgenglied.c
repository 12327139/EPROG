#include<stdio.h>
#include<math.h>

int main() {
    int n = 0;

    printf("n = ");
    scanf("%d", &n);
    
    double a_n = pow(-1, n) / (n + 2.);
    printf("a_%d = %lf\n", n, a_n);

    return 0;
}