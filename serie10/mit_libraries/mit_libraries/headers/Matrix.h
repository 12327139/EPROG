#ifndef MATRIX_H
#define MATRIX_H

#include<vector>
#include<string>
#include "Vector.h"

// aus Skriptum, Abschnitt 53
class Matrix {
private:
    std::vector<std::vector<double>> coefficients;
public:
    Matrix(int n = 0, int m = 0, double init = 0);
    Matrix(const Matrix& src); // Kopierkonstruktor
    const std::vector<double>& getRow(int i);
    const std::vector<double> getColumn(int i); // Keine Referenzen von Arrays/Vektoren möglich laut C++-Skriptum Abschnitt 45
    int countRows();
    int countColumns();
    const double& get(int i, int j);
    void set(int i, int j, double value);
    Vector multiplyVectorRight(Vector& x); // 10.2 
    Matrix transpose(); // 10.5
    Matrix scalarMultiply(double a); // 10.5
    Matrix rightMultiply(Matrix B); // 10.5
    double L_norm(int p, int q); // 10.6
    void swapRows(int i, int j); // 10.7
    std::string to_string(); // optional
};

#endif