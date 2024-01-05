#include <iostream>

#include "headers/Complex.h"
#include "headers/ComplexVector.h"
#include "headers/Matrix.h"

using std::cout;
using std::endl;

Complex scalarProduct(ComplexVector& u, ComplexVector& v) {
    try {
        if (u.size() != v.size()) throw u.size();

        Complex sum = Complex(0, 0);
        for (int i = 0; i < u.size(); i++) {
            Complex product = u.getEntry(i).times(v.getEntry(i));
            sum = sum.plus(product);
        }
        
        return sum;
    } catch (int size) {
        cout << "Die beiden Vektoren haben nicht die gleiche Länge";
        std::abort();
    }
}

ComplexVector sum(ComplexVector& u, ComplexVector& v) {
    try {
        if (u.size() != v.size()) throw u.size();

        ComplexVector vector_sum = ComplexVector(u.size(), Complex(0, 0));
        for (int i = 0; i < u.size(); i++) {
            Complex sum = u.getEntry(i).plus(v.getEntry(i));
            vector_sum.setEntry(i, sum);
        }
        return vector_sum;
    } catch (int size) {
        cout << "Die beiden Vektoren haben nicht die gleiche Länge";
        std::abort();
    }
}

// 10.4
ComplexVector multiplyScalar(ComplexVector& v, Complex& z) {
    ComplexVector scaled_vector = ComplexVector(v.size());
    for (int i = 0; i < v.size(); i++) {
        Complex scaledEntry = v.getEntry(i).times(z);
        scaled_vector.setEntry(i, scaledEntry);
    }
    return scaled_vector;
}

// 10.4
ComplexVector conjugate(ComplexVector& v) {
    for (int i = 0; i < v.size(); i++) {
        Complex entry = v.getEntry(i);
        entry.setImmag(entry.getImmag() * -1);
        v.setEntry(i, entry);
    }
    return v;
}

// 10.4
Vector modulus(ComplexVector& v) {
    Vector mod = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        mod.get(i) = v.getEntry(i).abs().getReal();
    }
    return mod;
}

// 10.7
Matrix sortByRow(Matrix& A) {
    Matrix sorted = Matrix(A);
    for (int i = 0; i < sorted.countRows(); i++) {
        for (int j = 0; j < (sorted.countRows()-i)-1; j++) {
            if (sorted.getRow(j).at(0) > sorted.getRow(j+1).at(0)) {
                sorted.swapRows(j, j+1);
            }
        }
    }
    return sorted;
}

void test_10_1() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.1" << endl;
    cout << "--------------------" << endl;


    cout << "- Konstruktor ComplexVector(int n, Complex z)" << endl;
    ComplexVector cv = ComplexVector(3, Complex(0, 0));
    cout << cv.to_string() << endl;
    cout << endl;

    cout << "- Methode int ComplexVector::size()" << endl;
    cout << cv.to_string() << endl;
    cout << cv.size() << endl;
    cout << endl;

    cout << "- Methode void ComplexVector::setEntry(int i, Complex z)" << endl;
    cout << cv.to_string() << endl;
    cv.setEntry(2, Complex(3, 2));
    cout << cv.to_string() << endl;
    cout << endl;

    cout << "- Funktion scalarProduct(int i, Complex z)" << endl;
    ComplexVector cv1 = ComplexVector(3, Complex(1, 1));
    ComplexVector cv2 = ComplexVector(3, Complex(1, 1));
    cout << cv1.to_string() << endl;
    cout << cv2.to_string() << endl;
    cout << scalarProduct(cv1, cv2).to_string() << endl;
    cout << endl;
}

void test_10_2() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.2" << endl;
    cout << "--------------------" << endl;

    cout << "- Methode Vector Matrix::multiplyVectorRight(Vector x)" << endl;
    Matrix m = Matrix(4, 2, 1);
    cout << m.to_string() << endl;

    Vector v = Vector(2, 2);
    cout << m.multiplyVectorRight(v).to_string() << endl;
}

void test_10_3() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.3" << endl;
    cout << "--------------------" << endl;

    cout << "- Methode Vector ComplexVector::realPart()" << endl;
    ComplexVector cv = ComplexVector(3, Complex(5.2, 6.5));
    cout << cv.to_string() << endl;
    cout << "real: " << cv.realPart().to_string() << endl;
    cout << "immag: " << cv.immaginaryPart().to_string() << endl;
}

void test_10_4() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.4" << endl;
    cout << "--------------------" << endl;

    cout << "- Funktion ComplexVector multiplyScalar(ComplexVector v, Complex z)" << endl;
    
    ComplexVector cv = ComplexVector(3, Complex(1, 1));
    cout << cv.to_string() << endl;

    Complex c = Complex(2, 2);
    cout << c.to_string() << endl;

    ComplexVector scaled = multiplyScalar(cv, c);
    cout << scaled.to_string() << endl << endl;

    cout << "- Funktion ComplexVector conjugate(ComplexVector v)" << endl;
    ComplexVector conjugated = conjugate(cv);
    cout << conjugated.to_string() << endl << endl;

    cout << "- Funktion modulus(ComplexVector v)" << endl;
    Vector mod = modulus(cv);
    cout << mod.to_string() << endl << endl;
}

void test_10_5() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.5" << endl;
    cout << "--------------------" << endl;

    cout << "- Methode Matrix Matrix::transpose()" << endl;
    Matrix m = Matrix(3, 4, 3);
    cout << m.to_string() << endl;
    Matrix transposed = m.transpose(); // KO
    cout << transposed.to_string() << endl;

    cout << "- Methode Matrix Matrix::scalarMultiply(double a)" << endl;
    cout << m.to_string() << endl;
    Matrix scaled = m.scalarMultiply(3); // OK
    cout << scaled.to_string() << endl;
    
    cout << "- Methode rightMultiply(Matrix B)" << endl;
    cout << m.to_string() << endl; 
    Matrix m2 = Matrix(4, 3, 2);
    cout << m2.to_string() << endl; 
    Matrix multiplied = m.rightMultiply(m2);
    cout << multiplied.to_string() << endl;
}

void test_10_6() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.6" << endl;
    cout << "--------------------" << endl;

    Matrix m = Matrix(3, 3, 2);
    double norm = m.L_norm(2, 4);
    cout << "- Methode double Matrix::L_norm(int p, int q)" << endl;
    cout << norm << endl;
}

void test_10_7() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.7" << endl;
    cout << "--------------------" << endl;

    cout << "- Methode void Matrix::swapRows(int i, int j)" << endl;

    Matrix m = Matrix(3, 3);
    for (int i = 0; i < m.countColumns(); i++) {
        m.set(i, 0, 1);
    }
    cout << m.to_string() << endl;

    m.swapRows(0, 1);
    cout << m.to_string() << endl;

    cout << "- Funktion Matrix sortByRow(Matrix M)" << endl;
    Matrix m2 = Matrix(3, 3, 0);
    double value = m2.countRows();
    for (int i = 0; i < m2.countColumns(); i++) {
        for (int j = 0; j < m2.countRows(); j++) {
            m2.set(j, i, value);
        }
        value--;
    }
    cout << m2.to_string() << endl;
    Matrix sorted = sortByRow(m2);
    cout << sorted.to_string() << endl;
}

int main() {
    // test_10_1();
    // test_10_2(); 
    // test_10_3();
    // test_10_4();
    // test_10_5();
    // test_10_6();
    // test_10_7();
    return 0;
}