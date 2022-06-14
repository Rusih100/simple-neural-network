#ifndef LAB_08_NEURON_NETWORK_H
#define LAB_08_NEURON_NETWORK_H

#include <neural_layer.h>
#include <iostream>
#include <vector>

using namespace std;

class Neuron_network {
    // Класс инициализирующий нейронную сеть и ее веса

private:
    // Параметры нейросети
    unsigned int number_hidden_layers; // Колличество скрытых слоев
    unsigned int neurons_per_layer;    // Нейронов на слой
    unsigned int number_inputs;        // Колличество входов
    unsigned int number_outputs;       // Колличество выходов

    // Слои
    vector<Neural_layer> network_layers;

public:
    Neuron_network(const Neuron_network& other);

    // Конструктор со значениями по умолчанию
    explicit Neuron_network(
            unsigned int hidden_layers_n = 2,
            unsigned int neurons_per_layer_n = 3,
            unsigned int inputs_n = 2,
            unsigned int outputs_n = 1
            );

    // Запуск нейросети с вектором значений
    vector<float> run(const vector<float>& input_values);

    // Выводит все веса нейросети
    void print_weights();

    Neuron_network& operator = (const Neuron_network& other);

    // TODO: Функция выбора слоя и смены случайного его веса
};

#endif
