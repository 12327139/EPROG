#include<stdio.h>
#include<math.h>
#include<assert.h>

int wurzelschranke(double x) {
    assert(x >= 0);
    return pow(x, 0.5);
}

int main() {
    double x = 0;

    printf("x=");
    scanf("%lf", &x);

    int schranke = wurzelschranke(x);
    printf("Wurzelschranke von %lf = %d\n", x, schranke);

    return 0;
}