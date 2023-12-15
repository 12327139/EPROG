#include<iostream>
#include<vector>

using std::vector;

class Polynomial {
private:
    vector<double> coefficients;
    int grad;
public:
    Polynomial(int grad);
    int degree();
    vector<double> getCoefficients();
    void setCoefficients(vector<double> coefficients);
    void print();
};

Polynomial::Polynomial(int grad) {
    try {
        if (grad < 0) {
            throw grad;
        }
        this->coefficients = vector<double>(grad + 1);
        this->grad = grad;
    } catch (int grad) {
        this->grad = 0;
        this->coefficients = vector<double>(1);
    }
}

int Polynomial::degree() {
    return this->grad;
}

vector<double> Polynomial::getCoefficients() {
    return this->coefficients;
}

void Polynomial::setCoefficients(vector<double> coefficients) {
    this->coefficients = coefficients;
}

void Polynomial::print() {
    if (grad == 0) {
        std::cout << "0 (Null-Polynom)" << std::endl;
        return;
    }

    for (int i = coefficients.size() - 1; i > 0; i--) {
        std::cout << coefficients.at(i) << "x^" << i << " + "; // x^i, nicht x^(i+1)
    }
    std::cout << coefficients.at(0) << " (Grad=" << this->grad << ")";
    std::cout << std::endl;
}

int main() {
    // Test: richtige Parameter
    vector<double> coefficients = {4, 2, 5.4, 8};
    Polynomial p1 = Polynomial(coefficients.size()-1);
    p1.setCoefficients(coefficients);
    p1.print();

    // Test: negativer Grad
    Polynomial p2 = Polynomial(-2);
    p2.print();

    return 0;
}
