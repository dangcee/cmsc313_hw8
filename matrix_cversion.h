// matrix_cversion.h
// this is the header file for the c version of my matrix library 

#ifndef MATRIX_cversion_H
#define MATRIX_cversion_H

typedef struct {
    int rows, cols;
    int** data;
} Matrix;

Matrix createMatrix(int rows, int cols);
void freeMatrix(Matrix m);
void setMatrix(Matrix* m, int r, int c, int val);
int getMatrix(Matrix m, int r, int c);
Matrix addMatrix(Matrix a, Matrix b);
Matrix multiplyMatrix(Matrix a, Matrix b);
Matrix transposeMatrix(Matrix m);
Matrix scalarMultiplyMatrix(Matrix m, int scalar);
void printMatrix(Matrix m);

#endif
