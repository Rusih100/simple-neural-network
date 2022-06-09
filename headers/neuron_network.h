#ifndef LAB_08_NEURON_NETWORK_H
#define LAB_08_NEURON_NETWORK_H

#include <neural_layer.h>
#include <iostream>
#include <vector>

using namespace std;

class Neuron_network {

private:
    // Параметры
    static const int neurons_per_layer = 3;  // Нейронов на слой
    static const int number_inputs = 2;      // Колличество входов
    static const int number_outputs = 1;     // Колличество выходов

    // Слои
    // TODO: Переписать в вектор
    Neural_layer L1;
    Neural_layer L2;
    Neural_layer Out;

public:
    Neuron_network();

    // Запуск нейросети с вектором значений
    vector<float> run(const vector<float>& input_values);

    void training(
            const vector <vector<float>>& dataset_input,
            const vector <vector<float>>& dataset_output,
            unsigned int number_epochs
            );

    // TODO: Написать алгоритм среднеквадратической ошибки
    // TODO: Написать алгоритм обучения
};

#endif
