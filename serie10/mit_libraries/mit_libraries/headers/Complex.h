#ifndef COMPLEX_H
#define COMPLEX_H

#include<string>

class Complex {
private:
    double real;
    double immag;
public:
    Complex(double real, double immag);
    Complex(const Complex& input); // Kopierkonstruktor
    double getReal();
    double getImmag();
    void setReal(double real);
    void setImmag(double immag);
    Complex plus(Complex z); // optional
    Complex times(Complex z); // optional
    Complex abs(); // optional
    std::string to_string(); // optional
};

#endif