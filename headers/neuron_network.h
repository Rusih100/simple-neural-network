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

    // Качает вес нейросети с определенной точностью
    void update_random_weight(unsigned int decimal_places);

    Neuron_network& operator = (const Neuron_network& other);

};

#endif
