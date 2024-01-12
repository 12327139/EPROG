#include <iostream>
#include<cmath>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// aus Skriptum, Abschnitt 49
class Vector {
private:
    vector<double> coefficients;
public:
    Vector(int dim = 0, double init = 0);
    double get(int index);
    const double& getConstRef(int k) const;
    void set(int index, double value);
    int size() const; 
    void print() const;
};

Vector::Vector(int dim, double init) {
    if (dim < 1) {
        cout << "Fehler: Der Vektor muss mindestens die Laenge 1 haben - dim=" << dim << endl;
        std::abort();
    }
    this->coefficients = vector<double>(dim, init);
}

int Vector::size() const {
    return coefficients.size();
}

double Vector::get(int index) {
    if (index < 0 || index >= this->size()) {
        cout << "Fehler: Der Index ist ausserhalb des Vektors - index=" << index << endl;
    }
    return coefficients.at(index);
}

const double& Vector::getConstRef(int k) const {
    if (k < 0 || k >= this->size()) {
        cout << "Fehler: Der Index ist ausserhalb des Vektors - k=" << k << endl;
    }
    return coefficients.at(k);
}

void Vector::set(int index, double value) {
    if (index < 0 || index >= this->size()) {
        cout << "Fehler: Der Index ist ausserhalb des Vektors - index=" << index << endl;
    }
    this->coefficients.at(index) = value;
}

void Vector::print() const {
    cout << "[";
    for (int i = 0; i < this->size()-1; i++) {
        cout << this->coefficients.at(i);
        cout << ", ";
    }
    cout << this->coefficients.at(this->coefficients.size()-1);
    cout << "]";
}

class Complex {
private:
    double real;
    double immag;
public:
    Complex(double real, double immag);
    Complex(const Complex& input);
    double getReal() const;
    double getImmag() const;
    void setReal(double real);
    void setImmag(double immag);
    Complex plus(Complex z) const;
    Complex times(Complex z) const;
    Complex abs() const;
    void print() const;
};

Complex::Complex(double real, double immag) {
    this->real = real;
    this->immag = immag;
}

Complex::Complex(const Complex& input) {
    this->real = input.real;
    this->immag = input.immag;
}

double Complex::getReal() const {
    return this->real;
}

double Complex::getImmag() const {
    return this->immag;
}

void Complex::setReal(double real) {
    this->real = real;
}

void Complex::setImmag(double immag) {
    this->immag = immag;
}

Complex Complex::plus(Complex z) const {
    double real = this->real + z.real;
    double immag = this->immag + z.immag;
    Complex sum = Complex(real, immag);
    return sum;
}

Complex Complex::times(Complex z) const {
    double real = (this->real * z.real) - (this->immag * z.immag);
    double immag = (this->real * z.immag) + (this->immag * z.real);
    return Complex(real, immag);
}

Complex Complex::abs() const {
    double real = this->getReal();
    double immag = this->getImmag();
    real = sqrt(real*real + immag*immag);
    return Complex(real, 0);
}

void Complex::print() const {
    cout << this->real;
    if (this->immag >= 0) {
        cout << "+";
    }
    cout << this->immag << "i";
}

class ComplexVector {
private:
    vector<Complex> coefficients;
public:
    ComplexVector(int n, Complex z = Complex(0, 0));
    int size() const;
    Complex get(int i) const;
    const Complex& getConstRef(int i) const;
    void set(int i, Complex z);
    Vector realPart() const; // 10.3
    Vector immaginaryPart() const; // 10.3
    void print() const;
};

ComplexVector::ComplexVector(int n, Complex z) {
    if (n < 1) {
        cout << "Fehler: Ein Vektor muss mindestens die Länge 1 haben - n=" << n << endl;
        std::abort();
    }
    this->coefficients = vector<Complex>(n, z);
}

int ComplexVector::size() const {
    return this->coefficients.size();
}

Complex ComplexVector::get(int i) const {
    if (i < 0 || i >= this->size()) {
        cout << "Fehler: Der Index ist ausserhalb des Vektors - i=" << i << endl;
        std::abort();
    }
    return this->coefficients.at(i);
}

const Complex& ComplexVector::getConstRef(int i) const {
    if (i < 0 || i >= this->size()) {
        cout << "Fehler: Der Index ist ausserhalb des Vektors - i=" << i << endl;
        std::abort();
    }
    return this->coefficients.at(i);
}

void ComplexVector::set(int i, Complex z) {
    if (i < 0 || i >= this->size()) {
        cout << "Fehler: Der Index ist ausserhalb des Vektors - i=" << i << endl;
        std::abort();
    }
    this->coefficients.at(i) = z;
}

Vector ComplexVector::realPart() const {
    Vector real = Vector(this->coefficients.size());
    for (int i = 0; i < real.size(); i++) {
        real.set(i, this->get(i).getReal());
    }
    return real;
}

Vector ComplexVector::immaginaryPart() const {
    Vector immag = Vector(this->coefficients.size());
    for (int i = 0; i < immag.size(); i++) {
        immag.set(i, this->get(i).getImmag());
    }
    return immag;
}

void ComplexVector::print() const {
    cout << "[";
    for (int i = 0; i < this->size()-1; i++) {
        this->getConstRef(i).print();
        cout << (", ");
    }
    this->getConstRef(this->size() - 1).print();
    cout << "]";
}

// aus Skriptum, Abschnitt 53
class Matrix {
private:
    vector<vector<double>> coefficients;
public:
    Matrix(int n = 0, int m = 0, double init = 0);
    Matrix(const Matrix& src);
    const vector<double>& getRowConstRef(int i) const;
    const vector<double> getColumn(int i);
    int countRows() const;
    int countColumns() const;
    const double& getConstRef(int i, int j);
    void set(int i, int j, double value);
    Vector multiplyVectorRight(Vector& x); // 10.2 
    Vector multiplyVectorLeft(Vector& y); // 10.2
    Matrix transpose(); // 10.5
    Matrix scalarMultiply(double a); // 10.5
    Matrix rightMultiply(Matrix B); // 10.5
    double L_norm(int p, int q); // 10.6
    void swapRows(int i, int j); // 10.7
    void print() const;
};

Matrix::Matrix(int rows, int columns, double init) : coefficients(rows, vector<double>(columns, init)) {}

Matrix::Matrix(const Matrix& src) {
    this->coefficients = src.coefficients;
}
           
const vector<double>& Matrix::getRowConstRef(int i) const {
    if (i < 0 || i >= this->countRows()) {
        cout << "Fehler: Der Zeilenindex ist ausserhalb der Matrix - i=" << i << endl;
    }
    return coefficients.at(i);
}

const vector<double> Matrix::getColumn(int i) {
    if (i < 0 || i >= this->countRows()) {
        cout << "Fehler: Der Spaltenindex ist ausserhalb der Matrix - i=" << i << endl;
        std::abort();
    }

    int size = this->coefficients.size();
    vector<double> column = vector<double>(size);
    for (int i = 0; i < size; i++) {
        column.push_back(this->getRowConstRef(i).at(0));
    }
    return column;
}

int Matrix::countRows() const {
    return this->coefficients.size();
}

int Matrix::countColumns() const {
    return this->coefficients.at(0).size();
}

const double& Matrix::getConstRef(int row, int column) {
    if (column < 0 || column >= this->countColumns() || row < 0 || row >= this->countRows()) {
        cout << "Fehler: Der Index ist ausserhalb der Matrix - column=" << column << ", row=" << row << endl;
        std::abort();
    }
    return coefficients[row][column];
}

void Matrix::set(int row, int column, double value) {
    if (column < 0 || column >= this->countColumns() || row < 0 || row >= this->countRows()) {
        cout << "Fehler: Der Index ist ausserhalb der Matrix - column=" << column << ", row=" << row << endl;
        std::abort();
    }
    this->coefficients[row][column] = value;
}

Vector Matrix::multiplyVectorRight(Vector& x) {
    int m = this->countRows();
    int n = this->countColumns();
    if (x.size() != n) {
        cout << "Fehler: Die Anzahl der Reihen der Matrix ist ungleich der Länge des Vektors - n=" << n << endl;
        std::abort();
    }

    Vector Ax = Vector(m);
    for (int i = 0; i < m; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += this->getConstRef(i,j) * x.getConstRef(j);
        }
        Ax.set(i, sum);
    }
    return Ax;
}

Vector Matrix::multiplyVectorLeft(Vector& y) {
    int m = this->countRows();
    int n = this->countColumns();
    if (y.size() != m) {
        cout << "Fehler: Die Anzahl der Spalten der Matrix ist ungleich der Länge des Vektors - m=" << m << endl;
        std::abort();
    }   

    Vector yTA = Vector(n);
    for (int i = 0; i < m; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum += this->getConstRef(j,i) * y.getConstRef(j);
        }
        yTA.set(i, sum);
    }
    return yTA;
}

Matrix Matrix::transpose() {
    int num_rows_transposed = this->countColumns();
    int num_columns_transposed = this->countRows();
    
    Matrix transposed = Matrix(num_rows_transposed, num_columns_transposed);

    for (int row = 0; row < this->countRows(); row++) {
        for (int column = 0; column < this->countColumns(); column++) {
            transposed.set(column, row, this->getConstRef(row, column));
        }
    }

    return transposed;
}

Matrix Matrix::scalarMultiply(double a) {
    Matrix scaled = Matrix(this->countRows(), this->countColumns());
    for (int row = 0; row < this->countRows(); row++) {
        for (int column = 0; column < this->countColumns(); column++) {
            scaled.set(column, row, this->getConstRef(column, row) * a);
        }
    }
    return scaled;
}

Matrix Matrix::rightMultiply(Matrix B) {
    
    if (this->countColumns() != B.countRows()) {
        cout << "Fehler: Die Anzahl der Spalten der ersten Matrix ist ungleich der Anzahl der Zeilen der zweiten Matrix - this=" << this->countColumns() << ", B=" << B.countRows() << endl;
        std::abort();
    }
    
    int m = this->countColumns();
    int p = B.countRows();
    int n = this->countRows();

    Matrix multiplied = Matrix(m, p);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < p; k++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                sum += this->getConstRef(i, j) * B.getConstRef(j, k);
            }
            multiplied.set(i, k, sum);
        }
    }
    
    return multiplied;
}

double Matrix::L_norm(int p, int q) {
    int n = this->countColumns();
    int m = this->countRows();

    double outer_sum = 0;
    for (int j = 0; j < m; j++) {
        double inner_sum = 0;
        for (int i = 0; i < n; i++) {
            inner_sum += pow(abs(this->getConstRef(i, j)), p);
        }   
        outer_sum += pow(inner_sum, q/p);
    }
    return pow(outer_sum, 1/q);
}

void Matrix::swapRows(int i, int j) {
    if (i < 0 || i >= this->countRows()) {
        cout << "Fehler: Der Zeilenindex i ist ausserhalb der Matrix - i=" << i << endl;
        std::abort();
    }
    if (j < 0 || j >= this->countRows()) {
        cout << "Fehler: Der Zeilenindex j ist ausserhalb der Matrix - j=" << j << endl;
        std::abort();
    }

    vector<double> tmp = this->coefficients.at(i);
    this->coefficients.at(i) = this->coefficients.at(j); 
    this->coefficients.at(j) = tmp;
}

void Matrix::print() const {
    for (int row = 0; row < this->countRows(); row++) {
        cout << "[";
        for (int column = 0; column < this->countColumns()-1; column++) {
            cout << this->getRowConstRef(row).at(column);
            cout << ", ";
        }
        cout << this->getRowConstRef(row).at(this->countColumns()-1);
        cout << "]" << endl;   
    }
}

// Funktionen

// 10.1
Complex scalarProduct(const ComplexVector& u, const ComplexVector& v) {
    if (u.size() != v.size()) {
        cout << "Fehler: Die beiden Vektoren haben nicht die gleiche Länge - u=" << u.size() << ", v=" + v.size() << endl;
        std::abort();
    }

    Complex sum = Complex(0, 0);
    for (int i = 0; i < u.size(); i++) {
        Complex product = u.get(i).times(v.get(i));
        sum = sum.plus(product);
    }
    
    return sum;
}

// 10.1
ComplexVector sum(const ComplexVector& u, const ComplexVector& v) {
    if (u.size() != v.size()) {
        cout << "Fehler: Die beiden Vektoren haben nicht die gleiche Länge - u=" << u.size() << ", v=" + v.size() << endl;
        std::abort();
    }

    ComplexVector vector_sum = ComplexVector(u.size(), Complex(0, 0));
    for (int i = 0; i < u.size(); i++) {
        Complex sum = u.get(i).plus(v.get(i));
        vector_sum.set(i, sum);
    }
    return vector_sum;
}

// 10.4
ComplexVector multiplyScalar(ComplexVector v, const Complex& z) {
    for (int i = 0; i < v.size(); i++) {
        Complex scaledEntry = v.get(i).times(z);
        v.set(i, scaledEntry);
    }
    return v;
}

// 10.4
ComplexVector conjugate(ComplexVector v) {
    for (int i = 0; i < v.size(); i++) {
        Complex entry = v.getConstRef(i);
        entry.setImmag(entry.getImmag() * -1);
        v.set(i, entry);
    }
    return v;
}

// 10.4
Vector modulus(const ComplexVector& v) {
    Vector mod = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        mod.set(i, v.get(i).abs().getReal());
    }
    return mod;
}

// 10.7
Matrix sortByRow(Matrix A) {
    // bubble-sort
    for (int i = 0; i < A.countRows(); i++) {
        for (int j = 0; j < (A.countRows()-i)-1; j++) {
            if (A.getRowConstRef(j).at(0) > A.getRowConstRef(j+1).at(0)) {
                A.swapRows(j, j+1);
            }
        }
    }
    return A;
}

// Testfunktionen

void test_10_1() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.1" << endl;
    cout << "--------------------" << endl;

    cout << "- Konstruktor ComplexVector(int n, Complex z)" << endl;
    ComplexVector cv = ComplexVector(3, Complex(0, 0));
    cv.print();
    cout << endl << endl;

    cout << "- Methode int ComplexVector::size()" << endl;
    cv.print();
    cout << endl;
    cout << cv.size() << endl;
    cout << endl;

    cout << "- Methode void ComplexVector::setEntry(int i, Complex z)" << endl;
    cv.print();
    cout << endl;
    cv.set(2, Complex(3, 2));
    cv.print();
    cout << endl << endl;

    cout << "- Funktion scalarProduct(int i, Complex z)" << endl;
    ComplexVector cv1 = ComplexVector(3, Complex(1, 0));
    ComplexVector cv2 = ComplexVector(3, Complex(1, 0));
    cv1.print();
    cout << endl;
    cv2.print();
    cout << endl;
    scalarProduct(cv1, cv2).print();
    cout << endl << endl;
}

void test_10_2() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.2" << endl;
    cout << "--------------------" << endl;

    cout << "- Methode Vector Matrix::multiplyVectorRight(Vector x)" << endl;
    Matrix m = Matrix(4, 2, 1);
    m.print();
    cout << endl;

    Vector v = Vector(2, 2);
    m.multiplyVectorRight(v).print();
    cout << endl;

    Vector v2 = Vector(4, 2);
    m.multiplyVectorLeft(v2).print();
    cout << endl;
}

void test_10_3() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.3" << endl;
    cout << "--------------------" << endl;

    cout << "- Methode Vector ComplexVector::realPart()" << endl;
    ComplexVector cv = ComplexVector(3, Complex(5.2, 6.5));
    cv.print();
    cout << endl;
    cout << "real: "; 
    cv.realPart().print();
    cout << endl;
    cout << "immag: ";
    cv.immaginaryPart().print();
    cout << endl;
}

void test_10_4() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.4" << endl;
    cout << "--------------------" << endl;

    cout << "- Funktion ComplexVector multiplyScalar(ComplexVector v, Complex z)" << endl;
    
    ComplexVector cv = ComplexVector(3, Complex(1, 1));
    cv.print();
    cout << endl;

    Complex c = Complex(2, 2);
    c.print();
    cout << endl;

    ComplexVector scaled = multiplyScalar(cv, c);
    scaled.print();
    cout << endl << endl;

    cout << "- Funktion ComplexVector conjugate(ComplexVector v)" << endl;
    ComplexVector conjugated = conjugate(cv);
    conjugated.print();
    cout << endl << endl;

    cout << "- Funktion modulus(ComplexVector v)" << endl;
    Vector mod = modulus(cv);
    mod.print();
    cout << endl << endl;
}

void test_10_5() {
    cout << "--------------------" << endl;
    cout << "TEST: 10.5" << endl;
    cout << "--------------------" << endl;

    cout << "- Methode Matrix Matrix::transpose()" << endl;
    Matrix m = Matrix(3, 4, 3);
    m.set(0, 0, 9);
    m.print();
    cout << endl;
    Matrix transposed = m.transpose();
    transposed.print();
    cout << endl;

    cout << "- Methode Matrix Matrix::scalarMultiply(double a)" << endl;
    m.print();
    cout << endl;
    Matrix scaled = m.scalarMultiply(3);
    scaled.print();
    cout << endl;
    
    cout << "- Methode rightMultiply(Matrix B)" << endl;
    m.print();
    cout << endl; 
    Matrix m2 = Matrix(4, 3, 2);
    m2.print();
    cout << endl; 
    Matrix multiplied = m.rightMultiply(m2);
    multiplied.print();
    cout << endl;
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
    m.print();
    cout << endl;

    m.swapRows(0, 1);
    m.print();
    cout << endl;

    cout << "- Funktion Matrix sortByRow(Matrix M)" << endl;
    Matrix m2 = Matrix(3, 3, 0);
    double value = m2.countRows();
    for (int i = 0; i < m2.countColumns(); i++) {
        for (int j = 0; j < m2.countRows(); j++) {
            m2.set(j, i, value);
        }
        value--;
    }
    m2.print();
    cout << endl;
    Matrix sorted = sortByRow(m2);
    sorted.print();
    cout << endl;
}

int main() {
    // test_10_1(); // OK
    // test_10_2(); // OK
    // test_10_3(); // OK
    // test_10_4(); // OK
    // test_10_5(); // OK
    // test_10_6(); // OK
    // test_10_7(); // OK



    return 0;
}