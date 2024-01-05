#include<iostream>
#include<vector>

#include "../headers/ComplexVector.h"
#include "../headers/Complex.h"

ComplexVector::ComplexVector(int n, Complex z) {
    this->vector = std::vector<Complex>(n, z);
}

int ComplexVector::size() {
    return this->vector.size();
}

Complex& ComplexVector::getEntry(int i) {
    return this->vector.at(i);
}

void ComplexVector::setEntry(int i, Complex z) {
    this->vector.at(i) = z;
}

Vector ComplexVector::realPart() {
    Vector real = Vector(this->vector.size());
    for (int i = 0; i < real.size(); i++) {
        real.get(i) = this->getEntry(i).getReal();
    }
    return real;
}

Vector ComplexVector::immaginaryPart() {
    Vector immag = Vector(this->vector.size());
    for (int i = 0; i < immag.size(); i++) {
        immag.get(i) = this->getEntry(i).getImmag();
    }
    return immag;
}

std::string ComplexVector::to_string() {
    std::string str = "[";
    for (int i = 0; i < this->size()-1; i++) {
        str.append(this->getEntry(i).to_string());
        str.append(", ");
    }
    str.append(this->getEntry(this->size() - 1).to_string());
    str.append("]");
    return str;
}