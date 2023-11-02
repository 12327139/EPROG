#include<stdio.h>
#include<assert.h>
#include<math.h>

double geometricMean(double x[]){
    assert(x[0] >= 0);   
    assert(x[1] >= 0);   
    assert(x[2] >= 0);

    return cbrt(x[0]*x[1]*x[2]);
}

int main() {

    double x[3] = {0,0,0};
    printf("x[0]=");
    scanf("%lf", &x[0]); 
    printf("x[1]=");
    scanf("%lf", &x[1]);
    printf("x[2]=");
    scanf("%lf", &x[2]);

    double ergebnis = geometricMean(x);
    printf("ergebnis=%lf\n", ergebnis);

    return 0;
}