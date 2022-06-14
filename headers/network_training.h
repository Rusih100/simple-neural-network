#ifndef LAB_08_NETWORK_TRAINING_H
#define LAB_08_NETWORK_TRAINING_H

#include <iostream>
#include <neuron_network.h>

class Network_training {
    // Класс обучения нейронной сети методом эволюции

private:
    // Датасеты
    vector <vector<float>> dataset_input;    // Вектор датасетов
    vector <vector<float>> dataset_output;   // Результаты датасетов

    unsigned int number_epochs;              // Колличество эпох обучения

    // Параметры генерируемой нейросети
    unsigned int number_hidden_layers;       // Колличество скрытых слоев
    unsigned int neurons_per_layer;          // Нейронов на слой
    unsigned int number_inputs;              // Колличество входов
    unsigned int number_outputs;             // Колличество выходов

    // Подсчет ошибки
    // Среднеквадратичная ошибка
    static float mean_squared_error(const vector<float>& x_true, const vector<float>& x);

public:
    Network_training(
            const vector <vector<float>>& dataset_input,
            const vector <vector<float>>& dataset_output,

            unsigned int hidden_layers_n = 2,
            unsigned int neurons_per_layer_n = 3,
            unsigned int inputs_n = 2,
            unsigned int outputs_n = 1
            );

    // Тренировка нейросети
    Neuron_network training(unsigned int numberEpochs, unsigned int step_for_epochs = 10);


};

#endif
