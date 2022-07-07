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

    // Обучаемая нейросеть
    Neuron_network network;

    // Подсчет ошибки методом среднеквадратичной ошибки
    static float mean_squared_error(const vector<float>& x_true, const vector<float>& x);

public:
    Network_training(
            const vector <vector<float>>& dataset_input,
            const vector <vector<float>>& dataset_output,
            const Neuron_network& network
            );

    // Тренировка нейросети методом эволюции
    Neuron_network training(unsigned int number_epochs);


};

#endif
