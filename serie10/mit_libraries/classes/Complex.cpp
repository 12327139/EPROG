#include<iostream>
#include<cmath>

#include "../headers/Complex.h"

Complex::Complex(double real, double immag) {
    this->real = real;
    this->immag = immag;
}

Complex::Complex(const Complex& input) {
    this->real = input.real;
    this->immag = input.immag;
}

double Complex::getReal() {
    return this->real;
}

double Complex::getImmag() {
    return this->immag;
}

void Complex::setReal(double real) {
    this->real = real;
}

void Complex::setImmag(double immag) {
    this->immag = immag;
}

Complex Complex::plus(Complex z) {
    double real = this->real + z.real;
    double immag = this->immag + z.immag;
    Complex sum = Complex(real, immag);
    return sum;
}

Complex Complex::times(Complex z) {
    double real = (this->real * z.real) - (this->immag * z.immag);
    double immag = (this->real * z.immag) + (this->immag * z.real);
    return Complex(real, immag);
}

Complex Complex::abs() {
    double real = this->getReal();
    double immag = this->getImmag();
    real = sqrt(real*real + immag*immag);
    return Complex(real, 0);
}

std::string Complex::to_string() {
    std::string str = "";
    str.append(std::to_string(this->real));
    if (this->immag >= 0) {
        str.append("+");
    }
    str.append(std::to_string(this->immag));
    str.append("i");
    return str;
}