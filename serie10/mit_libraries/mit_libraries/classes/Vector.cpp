#include<iostream>
#include<vector>
#include<cmath>

#include "../headers/Vector.h"

Vector::Vector(int dim, double init) : coefficients(dim, init) {}

int Vector::size() {
    return coefficients.size();
}

double& Vector::get(int k) {
    return coefficients.at(k);
}

std::string Vector::to_string() {
    std::string str = "[";
    for (int i = 0; i < this->size()-1; i++) {
        str.append(std::to_string(this->coefficients.at(i)));
        str.append(", ");
    }
    str.append(std::to_string(this->coefficients.at(this->coefficients.size()-1)));
    str.append("]");
    return str;
}