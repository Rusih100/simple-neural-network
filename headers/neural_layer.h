#ifndef LAB_08_NEURAL_LAYER_H
#define LAB_08_NEURAL_LAYER_H

#include <matrix.h>

#define EXP 2.7182818284

class Neural_layer {

private:
    unsigned int number_of_neurons;  // Колличество нейронов
    Matrix weights;                  // Веса

    // Функция сигмоиды
    static float sigmoid_fx(float x);

public:

};

#endif
