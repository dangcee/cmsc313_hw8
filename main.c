// main.c
// example of the matrix functions, given in hw8 (c version)

#include "matrix_cversion.h"
#include <stdio.h>

int main() {
    Matrix A = createMatrix(2, 2);
    setMatrix(&A, 0, 0, 6); setMatrix(&A, 0, 1, 4);
    setMatrix(&A, 1, 0, 8); setMatrix(&A, 1, 1, 3);

    Matrix B = createMatrix(2, 3);
    setMatrix(&B, 0, 0, 1); setMatrix(&B, 0, 1, 2); setMatrix(&B, 0, 2, 3);
    setMatrix(&B, 1, 0, 4); setMatrix(&B, 1, 1, 5); setMatrix(&B, 1, 2, 6);

    Matrix C = createMatrix(2, 3);
    setMatrix(&C, 0, 0, 2); setMatrix(&C, 0, 1, 4); setMatrix(&C, 0, 2, 6);
    setMatrix(&C, 1, 0, 1); setMatrix(&C, 1, 1, 3); setMatrix(&C, 1, 2, 5);

    Matrix B3 = scalarMultiplyMatrix(B, 3);
    Matrix Ct = transposeMatrix(C);
    Matrix temp = multiplyMatrix(B3, Ct);
    Matrix D = addMatrix(A, temp);

    printf("Matrix A:\n");
    printMatrix(A);
    printf("Matrix B:\n");
    printMatrix(B);
    printf("Matrix C:\n");
    printMatrix(C);

    printf("D = A + (3 x B) x C^T\n");
    printf("Matrix D:\n");
    printMatrix(D);

    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    freeMatrix(B3);
    freeMatrix(Ct);
    freeMatrix(temp);
    freeMatrix(D);

    return 0;
}
