#ifndef LAB_08_NEURON_NETWORK_H
#define LAB_08_NEURON_NETWORK_H

#include <neural_layer.h>
#include <iostream>
#include <vector>

using namespace std;

class Neuron_network {

private:
    // Параметры
    static const int number_hidden_layers = 2; // Колличество скрытых слоев
    static const int neurons_per_layer = 3;    // Нейронов на слой
    static const int number_inputs = 2;        // Колличество входов
    static const int number_outputs = 1;       // Колличество выходов

    // Подсчет ошибки
    // Среднеквадратичная ошибка
    static float mean_squared_error(const vector<float>& x_true, const vector<float>& x);

    // Слои
    vector<Neural_layer> network_layers;

public:
    Neuron_network();

    // Запуск нейросети с вектором значений
    vector<float> run(const vector<float>& input_values);

    // Тренировка нейросети
    void training(
            const vector <vector<float>>& dataset_input,
            const vector <vector<float>>& dataset_output,
            unsigned int number_epochs
            );

    // Выводит все веса нейросети
    void print_weights();
};

#endif
