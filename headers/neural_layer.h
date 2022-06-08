#ifndef LAB_08_NEURAL_LAYER_H
#define LAB_08_NEURAL_LAYER_H

#include <matrix.h>

#define EXP 2.7182818284

class Neural_layer {

private:
    unsigned int number_neurons;  // Колличество нейронов
    unsigned int number_inputs;   // Колличество нейронов на прошлом слое
    Matrix weights;               // Веса

    // Функция сигмоиды
    static float sigmoid_fx(float x);

public:
    Neural_layer();

    // Конструктор, принимает колличество нейронов и колличество нейронов прошлого слоя
    Neural_layer(unsigned int number_neurons, unsigned int number_inputs);

    // Вычисляет выходные значения слоя
    Matrix run(Matrix input_values);

    Neural_layer& operator = (const Neural_layer& other);

};

#endif
