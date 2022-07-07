#ifndef LAB_08_NEURON_NETWORK_H
#define LAB_08_NEURON_NETWORK_H

#include <iostream>
#include <vector>
#include <cmath>

#include <random_generator.h>
#include <neural_layer.h>

using namespace std;

class Neuron_network {
    // Класс инициализирующий нейронную сеть и ее веса

    friend class Network_training;

private:
    // Параметры нейросети
    unsigned int number_hidden_layers; // Количество скрытых слоев
    unsigned int neurons_per_layer;    // Нейронов на слой
    unsigned int number_inputs;        // Количество входов
    unsigned int number_outputs;       // Количество выходов

    // Слои нейросети
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

    // Запуск нейросеть с вектором значений
    vector<float> run(const vector<float>& input_values);

    // Выводит все веса нейросети
    void print_weights();

    Neuron_network& operator = (const Neuron_network& other);

};

#endif
