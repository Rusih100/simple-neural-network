#ifndef LAB_08_NEURON_NETWORK_H
#define LAB_08_NEURON_NETWORK_H

#include <neural_layer.h>

class Neuron_network {

private:
    // Параметры
    static const int neurons_per_layer = 3;  // Нейронов на слой
    static const int number_inputs = 2;      // Колличество входов
    static const int number_outputs = 1;     // Колличество выходов

    // Слои
    Neural_layer L1;
    Neural_layer L2;
    Neural_layer Out;

public:
    // TODO: Дописать конструктор
    Neuron_network();

    // TODO: Написать алгоритм среднеквадратической ошибки
    // TODO: Написать алгоритм качания весов

    // TODO: Написать алгоритм обучения
};

#endif
