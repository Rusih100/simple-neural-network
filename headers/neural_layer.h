#ifndef LAB_08_NEURAL_LAYER_H
#define LAB_08_NEURAL_LAYER_H

#include <matrix.h>

#define EXP 2.7182818284

class Neural_layer {

private:
    unsigned int number_of_neurons;  // Колличество нейронов
    unsigned int number_of_inputs;   // Колличество нейронов на прошлом слое
    Matrix weights;                  // Веса

    // Функция сигмоиды
    static float sigmoid_fx(float x);

public:
    // Конструктор, принимает колличество нейронов и колличество нейронов прошлого слоя
    Neural_layer(unsigned int number_of_neurons, unsigned int number_of_inputs);

    // Вычисляет выходные значения слоя
    Matrix run(Matrix input_values);
};

#endif
