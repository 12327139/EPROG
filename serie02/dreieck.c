#include<stdio.h>
#include<math.h>

int main() {
    double hypotenuse = 0;
    double schenkel_1 = 0;
    double schenkel_2 = 0;

    // Eingabe und Zuordnung der Seiten
    {
        double a, b, c = 0;

        printf("Seite a = ");
        if (!scanf("%lf", &a) || a <= 0) {
            printf("Ungueltige Eingabe\n");
            return 1;
        }

        printf("Seite b = ");
        if (!scanf("%lf", &b) || b <= 0) {
            printf("Ungueltige Eingabe\n");
            return 1;
        }

        printf("Seite c = ");
        if (!scanf("%lf", &c) || c <= 0) {
            printf("Ungueltige Eingabe\n");
            return 1;
        }

        if (a >= b && a >= c) {
            hypotenuse = a;
            schenkel_1 = b;
            schenkel_2 = c;
        }
        else if (b >= a && b >= c) {
            hypotenuse = b;
            schenkel_1 = a;
            schenkel_2 = c;
        }
        else {
            hypotenuse = c;
            schenkel_1 = a;
            schenkel_2 = b;
        }
    }

    int isGleichseitig = schenkel_1 == schenkel_2 && schenkel_2 == hypotenuse;
    if (isGleichseitig) {
        printf("Das Dreieck ist gleichseitig\n");
    }

    int isGleichschenklig = schenkel_1 == schenkel_2 && schenkel_2 == hypotenuse; 
    if (isGleichschenklig) {
        printf("Das Dreieck ist gleichschenklig\n");
    }

    int isUnregelmaessig = schenkel_1 != schenkel_2 && schenkel_2 != hypotenuse;
    if (isUnregelmaessig) {
        printf("Das Dreieck ist unregelmaessig\n");
    }

    // BUG: Fehleranfällig wg. Ungenauigkeit von Gleitkommazahlen
    int isRechtwinklig = sqrt(pow(schenkel_1, 2) + pow(schenkel_2, 2)) == hypotenuse;
    if (isRechtwinklig) {
        printf("Das Dreieck ist rechtwinklig\n");
    }

    int isEntartet = hypotenuse == schenkel_1 + schenkel_2; 
    if (isEntartet) {
        printf("Das Dreieck ist 'entartet'\n");
    }

    int isUnmoeglich = hypotenuse > schenkel_1 + schenkel_2; 
    if (isUnmoeglich) {
        printf("Das Dreieck ist 'unmoeglich'\n");
    }

    return 0;
}