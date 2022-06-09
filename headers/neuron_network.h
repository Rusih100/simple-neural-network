#ifndef LAB_08_NEURON_NETWORK_H
#define LAB_08_NEURON_NETWORK_H

#include <neural_layer.h>
#include <vector>

class Neuron_network {

private:
    // Параметры
    static const int neurons_per_layer = 3;  // Нейронов на слой
    static const int number_inputs = 2;      // Колличество входов
    static const int number_outputs = 1;     // Колличество выходов

    // Тренировочные данные
    static Matrix dataset;
    static Matrix dataset_result;

    // Слои
    // TODO: Переписать в вектор
    Neural_layer L1;
    Neural_layer L2;
    Neural_layer Out;

public:
    Neuron_network();

    // Запуск нейросети с вектором значений
    std::vector<float> run(const std::vector<float>& input_values);

    // TODO: Написать алгоритм среднеквадратической ошибки
    // TODO: Написать алгоритм обучения
};

#endif
