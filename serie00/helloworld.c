#include<stdio.h> // Funktion printf nicht deklariert

int main() { // Kompiliert mit Warnung "return type defaults to int"
    printf("Hello, World!\n"); // Kompiliert nicht mehr (; vor return), ohne \n kein Zeilenumbruch
    return 0; // Kompiliert, kein Laufzeitfehler
}