#include <iostream>
#include<cmath>
#include<vector>

using std::cout;
using std::endl;

// Hilfsfunktion: Wandelt eine double-Variable in einen String um ohne nachgestellte Nullen
std::string double_to_string(double d) {
    std::string str = std::to_string(d);
    str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
    str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
    return str;
}

// aus Skriptum, Abschnitt 49
class Vector {
private:
    std::vector<double> coefficients;
public:
    Vector(int dim = 0, double init = 0);
    double& get(int k);
    int size(); 
    std::string to_string(); // Hilfsfunktion: Wandelt Vektor in einen String zum printen um.
};

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
        str.append(double_to_string(this->coefficients.at(i)));
        str.append(", ");
    }
    str.append(double_to_string(this->coefficients.at(this->coefficients.size()-1)));
    str.append("]");
    return str;
}

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
    Complex plus(Complex z); // Hilfsfunktion: Addition mit einer komplexen Zahl
    Complex times(Complex z); // Hilfsfunktion: Multiplikation mit einer komplexen Zahl
    Complex abs(); // Hilfsfunktion: Betrag einer komplexen Zahl
    std::string to_string(); // Hilfsfunktion: Wandelt Complex in einen String zum printen um
};

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
    str.append(double_to_string(this->real));
    if (this->immag >= 0) {
        str.append("+");
    }
    str.append(double_to_string(this->immag));
    str.append("i");
    return str;
}

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
    std::string to_string(); // Wandelt ComplexVector in einen string zum printen um
};

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

// aus Skriptum, Abschnitt 53
class Matrix {
private:
    std::vector<std::vector<double>> coefficients;
public:
    Matrix(int n = 0, int m = 0, double init = 0);
    Matrix(const Matrix& src); // Kopierkonstruktor
    const std::vector<double>& getRow(int i);
    const std::vector<double> getColumn(int i); // Keine Referenzen von Arrays/Vektoren möglich laut C++-Skriptum Abschnitt 45
    int countRows(); // Hilfsfunktion: Gibt die Anzahl der Reihen der Matrix zurück
    int countColumns(); // Hilfsfunktion: Gibt die Anzahl der Spalten der Matrix zurück
    const double& get(int i, int j);
    void set(int i, int j, double value);
    Vector multiplyVectorRight(Vector& x); // 10.2 
    Matrix transpose(); // 10.5
    Matrix scalarMultiply(double a); // 10.5
    Matrix rightMultiply(Matrix B); // 10.5
    double L_norm(int p, int q); // 10.6
    void swapRows(int i, int j); // 10.7
    std::string to_string(); // Wandelt Matrix in einen string zum printen um
};

Matrix::Matrix(int columns, int rows, double init) : coefficients(rows, std::vector<double>(columns, init)) {}

Matrix::Matrix(const Matrix& src) {
    this->coefficients = src.coefficients;
}

const std::vector<double>& Matrix::getRow(int i) {
    return coefficients.at(i);
}

const std::vector<double> Matrix::getColumn(int i) {
    int size = this->coefficients.size();
    std::vector<double> column = std::vector<double>(size);
    for (int i = 0; i < size; i++) {
        column.push_back(this->getRow(i).at(0));
    }
    return column;
}

int Matrix::countRows() {
    return this->coefficients.size();
}

int Matrix::countColumns() {
    return this->coefficients.at(0).size();
}

const double& Matrix::get(int column, int row) {
    return coefficients[row][column];
}

void Matrix::set(int column, int row, double value) {
    this->coefficients[row][column] = value;
}

Vector Matrix::multiplyVectorRight(Vector& x) {
    int m = this->countColumns();
    int n = this->countRows();
    if (x.size() != n) throw n;
    
    Vector Ax = Vector(m);
    for (int i = 0; i < m; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += this->get(i,j) * x.get(j);
        }
        Ax.get(i) = sum;
    }
    return Ax;
}

Matrix Matrix::transpose() {
    int num_rows_transposed = this->countColumns();
    int num_columns_transposed = this->countRows();
    
    Matrix transposed = Matrix(num_columns_transposed, num_rows_transposed);

    for (int row = 0; row < num_rows_transposed; row++) {
        for (int column = 0; column < num_rows_transposed; column++) {
            transposed.set(column, row, this->get(row, column));
        }
    }

    return transposed;
}

Matrix Matrix::scalarMultiply(double a) {
    Matrix scaled = Matrix(this->countColumns(), this->countRows());
    for (int row = 0; row < this->countRows(); row++) {
        for (int column = 0; column < this->countColumns(); column++) {
            scaled.set(column, row, this->get(column, row) * a);
        }
    }
    return scaled;
}

Matrix Matrix::rightMultiply(Matrix B) {
    if (this->countColumns() != B.countRows()) throw this->countColumns();
    
    int m = this->countColumns();
    int p = B.countRows();
    int n = this->countRows();

    Matrix multiplied = Matrix(m, p);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < p; k++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                sum += this->get(i, j) * B.get(j, k);
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
            inner_sum += pow(abs(this->get(i, j)), p);
        }   
        outer_sum += pow(inner_sum, q/p);
    }
    return pow(outer_sum, 1/q);
}

void Matrix::swapRows(int i, int j) {
    std::vector<double> tmp = this->coefficients.at(i);
    this->coefficients.at(i) = this->coefficients.at(j); 
    this->coefficients.at(j) = tmp;
}

std::string Matrix::to_string() {
    std::string str = "";
    for (int row = 0; row < this->countRows(); row++) {
        str.append("[");
        for (int column = 0; column < this->countColumns()-1; column++) {
            str.append(double_to_string(this->getRow(row).at(column)));
            str.append(", ");
        }
        str.append(double_to_string(this->getRow(row).at(this->countColumns()-1)));
        str.append("]\n");
        
    }
    return str;
}

// Funktionen

// 10.1
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

// 10.1
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
    // bubble-sort
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

// Testfunktionen

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
    test_10_1();
    test_10_2(); 
    test_10_3();
    test_10_4();
    test_10_5();
    test_10_6();
    test_10_7();
    return 0;
}