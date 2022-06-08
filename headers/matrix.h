#ifndef LAB_08_MATRIX_H
#define LAB_08_MATRIX_H

#include <vector>

class Matrix {

private:
    // Объявление матрицы
    float **data;

    unsigned int row;
    unsigned int colomn;

public:
    Matrix();
    Matrix(const Matrix& other);
    Matrix(const std::vector<float>& other);
    Matrix(unsigned int row, unsigned int colomn);
    ~Matrix();

    void print();

    float *operator [] (int i);

    Matrix operator * (const Matrix& other);
    Matrix& operator = (const Matrix& other);

    Matrix T(); // Транспонирование матрицы

    // Функция заполнения матрицы случайными числами
    void random_fill(int min , int max, unsigned int decimal_places = 0);

};

#endif
