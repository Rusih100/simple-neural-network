#include <matrix.h>
#include <iostream>
#include <random_generator.h>

Matrix::Matrix() {
    row = 0;
    colomn = 0;

    // Выделение памяти для матрицы
    data = new float * [row];
    for (int i = 0; i < row; ++i) {
        data[i] = new float [colomn];
    }

    // Заполнение матрицы нулями
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colomn; ++j) {
            data[i][j] = 0;
        }
    }
}


Matrix::Matrix(const Matrix& other) {
    row = other.row;
    colomn = other.colomn;

    // Выделение памяти для матрицы
    data = new float * [row];
    for (int i = 0; i < row; ++i) {
        data[i] = new float [colomn];
    }

    // Копирование значений другой матрицы
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colomn; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}


Matrix::Matrix(const std::vector<float>& other) {
    this->row = 1;
    this->colomn = other.size();

    // Выделение памяти для матрицы
    data = new float * [row];
    for (int i = 0; i < row; ++i) {
        data[i] = new float [colomn];
    }

    for (int i = 0; i < colomn; ++i) {
        data[0][i] = other[i];
    }

}


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
        for (int j = 0; j < colomn; ++j) {
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
    // Если количество столбцов m в первой матрице не равно количеству строк n во второй матрице,
    // то вызываем исключение
    if (colomn != other.row) {
        throw std::invalid_argument("The operation for these matrices is not possible, incompatible dimensions. \n");
    }

    Matrix result(row, other.colomn);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < other.colomn; ++j) {
            for (int k = 0; k < colomn; ++k) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}


Matrix& Matrix::operator=(const Matrix &other) {

    // Случай самокопирования
    if (this == &other){
        return *this;
    }

    row = other.row;
    colomn = other.colomn;

    // Выделение памяти для матрицы
    data = new float * [row];
    for (int i = 0; i < row; ++i) {
        data[i] = new float [colomn];
    }

    // Копирование значений другой матрицы
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colomn; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
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
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colomn; ++j) {
            data[i][j] = (float)random_double(min, max, decimal_places);
        }
    }
}

