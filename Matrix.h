// Matrix.h
// header file for the cpp version of the matrix program
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows, cols;

public:
    Matrix(int r, int c);
    void set(int r, int c, int val);
    int get(int r, int c) const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix transpose() const;
    Matrix scalarMultiply(int scalar) const;
    void print() const;
};

#endif
