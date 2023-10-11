#include<stdio.h>

int main(){
    double a, b, c, x = 0;

    printf("a = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("c = ");
    scanf("%lf", &c);

    printf("x = ");
    scanf("%lf", &x);

    double p_x = (a*x*x)+(b*x)+c; 
    printf("p(%lf)=%lf\n", x, p_x);

    return 0;
}
