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

    Matrix(unsigned int row, unsigned int colomn);
    ~Matrix();

    void print();

};


#endif
