#include<vector>
#include<iostream>
#include<cmath>

#include "../headers/Matrix.h"

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
            str.append(std::to_string(this->getRow(row).at(column)));
            str.append(", ");
        }
        str.append(std::to_string(this->getRow(row).at(this->countColumns()-1)));
        str.append("]\n");
        
    }
    return str;
}