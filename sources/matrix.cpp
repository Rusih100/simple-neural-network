#include <matrix.h>
#include <iostream>
#include <random_generator.h>

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

float *Matrix::operator[](int i) {
    return data[i];
}

Matrix Matrix::operator*(const Matrix& other) {

    Matrix result(row, other.colomn);

    // Если количество столбцов m в первой матрице не равно количеству строк n во второй матрице,
    // то вернется пустая матрица размера: n строк первой на m столбцов второй
    if (colomn != other.row) {
        std::cout << "ERROR! The operation for these matrices is not possible, an empty matrix was returned. \n";
        return result;
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < other.colomn; ++j) {
            for (int k = 0; k < colomn; ++k) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::T() {
    Matrix result(colomn, row);

    for (int i = 0; i < colomn; ++i) {
        for (int j = 0; j < row; ++j) {
            result[i][j] = data[j][i];
        }
    }
    return result;
}

void Matrix::random_fill(int min , int max, unsigned int decimal_places) {
    Random G(min, max, decimal_places);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colomn; ++j) {
            data[i][j] = (float)G.generate();
        }
    }
}

