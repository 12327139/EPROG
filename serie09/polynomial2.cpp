#include<iostream>
#include<vector>
#include<math.h>

using std::vector;

class Polynomial {
private:
    vector<double> coefficients;
    int grad;
public:
    Polynomial(int grad); // 9.3
    int degree(); // 9.3
    vector<double> getCoefficients(); // 9.3
    void setCoefficients(vector<double> coefficients); // 9.3
    Polynomial diff(); // 9.6
    Polynomial diff(int k); // 9.6
    double eval(double x); // 9.7
    Polynomial addPolynomial(Polynomial poly2); // 9.8
    void print();
};

Polynomial::Polynomial(int grad) {
    try {
        if (grad < 0) {
            throw grad;
        }
        this->coefficients = vector<double>(grad);
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
    for (int i = coefficients.size() - 1; i > 0; i--) {
        std::cout << coefficients.at(i) << "x^" << i << " + ";
    }
    std::cout << coefficients.at(0) << " (Grad=" << this->grad << ")";
    std::cout << std::endl;
}

Polynomial Polynomial::diff() {
    Polynomial abg_polynom = Polynomial(this->grad-1);
    
    vector<double> abg_coeff = this->coefficients;
    for (int i = 0; i < abg_coeff.size(); i++) {
        abg_coeff.at(i) = abg_coeff.at(i) * i;
    }
    abg_coeff.erase(abg_coeff.begin());
    abg_polynom.setCoefficients(abg_coeff);
    return abg_polynom;
}

Polynomial Polynomial::diff(int k) {
    Polynomial abl_poly = this->diff();
    for (int i = 0; i < k-1; i++) {
        abl_poly = abl_poly.diff();
    }
    return abl_poly;
}

double Polynomial::eval(double x) {
    double summe = 0;
    for (int i = 0; i < this->coefficients.size(); i++) {
        summe += coefficients.at(i) * pow(x, i);
    }
    return summe;
}

Polynomial Polynomial::addPolynomial(Polynomial poly2) {
    int gr_deg = poly2.degree();
    int sm_deg = this->degree();
    if(this->degree() >= poly2.degree()) {
        gr_deg = this->degree();
        sm_deg = poly2.degree();
    }

    Polynomial result = Polynomial(gr_deg);
    vector<double> coeff = vector<double>(gr_deg + 1);
    
    for(int i = 0; i < gr_deg + 1; i++) {
        if(i <= sm_deg) {
            coeff.at(i) = this->getCoefficients().at(i) + poly2.getCoefficients().at(i);
            continue; 
        } 
        
        if(gr_deg == this->degree()) {
            coeff.at(i) = this->getCoefficients().at(i);
        } else {
            coeff.at(i) = poly2.getCoefficients().at(i);
        }
    }
    
    result.setCoefficients(coeff);
    return result;
}

int main() {
    vector<double> coeff = {5, 4, 3, 2, 1};
    Polynomial poly = Polynomial(coeff.size()-1);
    poly.setCoefficients(coeff);

    std::cout << "Aufgabe 9.6: Ableitung" << std::endl;
    poly.print();
    for (int i = 1; i < coeff.size(); i++) {
        poly.diff(i).print();
    }
    std::cout << "----------" << std::endl;


    std::cout << "Aufgabe 9.7: eval" << std::endl;
    std::cout << poly.eval(0) << std::endl;
    std::cout << "----------" << std::endl;

    std::cout << "Aufgabe 9.8: Summe" << std::endl;
    vector<double> coeff1 = {3, 2, 1};
    Polynomial poly1 = Polynomial(coeff1.size()-1);
    poly1.setCoefficients(coeff1);

    vector<double> coeff2 = {4, 3, 2, 1};
    Polynomial poly2 = Polynomial(coeff2.size()-1);
    poly2.setCoefficients(coeff2);

    Polynomial summe = poly1.addPolynomial(poly2);
    summe.print();
    std::cout << "----------" << std::endl;

    return 0;
}
