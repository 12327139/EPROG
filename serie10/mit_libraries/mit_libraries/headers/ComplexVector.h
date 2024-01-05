#ifndef COMPLEXVECTOR_H
#define COMPLEXVECTOR_H

#include "Complex.h"
#include "Vector.h"
#include<vector>
#include<string>

class ComplexVector {
private:
    std::vector<Complex> vector;
public:
    ComplexVector(int n, Complex z = Complex(0, 0));
    int size();
    Complex& getEntry(int i);
    void setEntry(int i, Complex z);
    Vector realPart(); // 10.3
    Vector immaginaryPart(); // 10.3
    std::string to_string(); // optional
};

#endif