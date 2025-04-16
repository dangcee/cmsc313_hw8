// matrix.c
// the operations for matrices are all contained in this file, creation of matrix too (c version)

#include "matrix_cversion.h"
#include <stdio.h>
#include <stdlib.h>

Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i)
        m.data[i] = calloc(cols, sizeof(int));
    return m;
}

void freeMatrix(Matrix m) {
    for (int i = 0; i < m.rows; ++i)
        free(m.data[i]);
    free(m.data);
}

void setMatrix(Matrix* m, int r, int c, int val) {
    m->data[r][c] = val;
}

int getMatrix(Matrix m, int r, int c) {
    return m.data[r][c];
}

Matrix addMatrix(Matrix a, Matrix b) {
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; ++i)
        for (int j = 0; j < a.cols; ++j)
            result.data[i][j] = a.data[i][j] + b.data[i][j];
    return result;
}

Matrix multiplyMatrix(Matrix a, Matrix b) {
    Matrix result = createMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; ++i)
        for (int j = 0; j < b.cols; ++j)
            for (int k = 0; k < a.cols; ++k)
                result.data[i][j] += a.data[i][k] * b.data[k][j];
    return result;
}

Matrix transposeMatrix(Matrix m) {
    Matrix result = createMatrix(m.cols, m.rows);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            result.data[j][i] = m.data[i][j];
    return result;
}

Matrix scalarMultiplyMatrix(Matrix m, int scalar) {
    Matrix result = createMatrix(m.rows, m.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            result.data[i][j] = m.data[i][j] * scalar;
    return result;
}

void printMatrix(Matrix m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j)
            printf("%d ", m.data[i][j]);
        printf("\n");
    }
}
