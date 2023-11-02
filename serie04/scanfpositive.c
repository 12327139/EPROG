#include<stdio.h>
#include<assert.h>

double scanfpositive() {
    double tao = 0;

    do {
        printf("tao=");
        scanf("%lf", &tao);
    } while (tao <= 0);

    return 0.;
}

int main() {
    double eingegebeneZahl = scanfpositive();
    printf("Die Zahl %lf wurde eingegeben.\n", eingegebeneZahl);
    return 0;
}