#ifndef LAB_08_NEURAL_LAYER_H
#define LAB_08_NEURAL_LAYER_H

#include <matrix.h>
#include <iostream>

using namespace std;

#define EXP 2.7182818284

class Neural_layer {

private:
    unsigned int number_neurons;            // Колличество нейронов
    unsigned int number_inputs;             // Колличество нейронов на прошлом слое
    Matrix weights;                         // Веса

    static float sigmoid_fx(float x);       // Функция сигмоиды

public:
    Neural_layer();

    // Конструктор, принимает колличество нейронов и колличество нейронов прошлого слоя
    Neural_layer(unsigned int number_neurons, unsigned int number_inputs);

    // Вычисляет выходные значения слоя
    Matrix run(Matrix input_values);

    Neural_layer& operator = (const Neural_layer& other);

    // Выводит веса на экран
    void print();

};

#endif
