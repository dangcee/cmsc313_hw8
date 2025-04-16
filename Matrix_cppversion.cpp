// Matrix.cpp
// the operations for matrices are all contained in this file, creation of matrix too (cpp version)

#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int r, int c) : data(r, std::vector<int>(c, 0)), rows(r), cols(c) {}


void Matrix::set(int r, int c, int val) {
    data[r][c] = val;
}

int Matrix::get(int r, int c) const {
    return data[r][c];
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[j][i] = data[i][j];
    return result;
}

Matrix Matrix::scalarMultiply(int scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] * scalar;
    return result;
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (int val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
}
