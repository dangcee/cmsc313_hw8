// main.cpp
// example of the matrix functions, given in hw8 (cpp version)

#include "Matrix.h"
#include <iostream>

int main() {
    Matrix A(2, 2);
    A.set(0, 0, 6); A.set(0, 1, 4);
    A.set(1, 0, 8); A.set(1, 1, 3);

    Matrix B(2, 3);
    B.set(0, 0, 1); B.set(0, 1, 2); B.set(0, 2, 3);
    B.set(1, 0, 4); B.set(1, 1, 5); B.set(1, 2, 6);

    Matrix C(2, 3);
    C.set(0, 0, 2); C.set(0, 1, 4); C.set(0, 2, 6);
    C.set(1, 0, 1); C.set(1, 1, 3); C.set(1, 2, 5);

    Matrix D = A + (B.scalarMultiply(3) * C.transpose());

    std::cout << "Matrix A:" << std::endl;
    A.print();
    std::cout << "Matrix B:" << std::endl;
    B.print();
    std::cout << "Matrix C:" << std::endl;
    C.print();
    std::cout << "D = A + (3 x B) x C^T" << std::endl;
    std::cout << "Matrix D:" << std::endl;
    D.print();

    return 0;
}
