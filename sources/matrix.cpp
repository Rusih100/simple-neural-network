#include "matrix.h"
#include <iostream>

Matrix::Matrix(unsigned int n, unsigned int m) {
    this->row = n;
    this->colomn = m;

    // Выделение памяти для матрицы
    data = new float * [row];
    for (int i = 0; i < row; ++i) {
        data[i] = new float [colomn];
    }

    // Заполнение матрицы нулями
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < m; ++j) {
            data[i][j] = 0;
        }
    }

}

Matrix::~Matrix() {
    // Высвобождение памяти для матрицы
    for (int i = 0; i < row; ++i) {
        delete [] data[i];
    }
    delete [] data;
}

void Matrix::print() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colomn; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}

