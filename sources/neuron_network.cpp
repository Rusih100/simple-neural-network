#include <neuron_network.h>

float Neuron_network::mean_squared_error(const vector<float>& x_true, const vector<float>& x) {
    // Среднеквадратичная ошибка

    // Проверка входных данных
    // Вернет -1, если размерности векторов не совпадают
    if (x_true.size() != x.size()) {
        cout << "ERROR. The dimensions of the vectors do not match. Return -1\n ";
        return -1;
    }

    float sum = 0;
    for (int i = 0; i < x.size(); ++i) {
        sum += (x_true[i] - x[i]) * (x_true[i] - x[i]);
    }
    return sum / (float)x.size();
}


Neuron_network::Neuron_network() {

    Neural_layer input_Layer(neurons_per_layer, number_inputs);
    network_layers.push_back(input_Layer);

    for (int i = 0; i < number_hidden_layers - 1; ++i) {
        Neural_layer hidden_Layer(neurons_per_layer, neurons_per_layer);
        network_layers.push_back(hidden_Layer);
    }

    Neural_layer output_Layer(number_outputs, neurons_per_layer);
    network_layers.push_back(output_Layer);
}


vector<float> Neuron_network::run(const vector<float>& input_values) {

    vector<float> result(number_outputs);

    // Проверка входных данных
    if (input_values.size() != number_inputs){
        cout << "ERROR! The input data does not correspond to the dimension of the neural network.\n";
        return result;
    }

    // Вычисления
    Matrix temp(input_values);

    for (auto & layer : network_layers) {
        temp = layer.run(temp);
    }

    for (int i = 0; i < number_outputs; ++i) {
        result[i] = temp[0][i];
    }

    return result;
}


void Neuron_network::training(
        const vector <vector<float>>& dataset_input,     // Датасеты
        const vector <vector<float>>& dataset_output,    // Результаты датасетов
        unsigned int number_epochs                       // Количество эпох обучения
        ) {

    // Проверки датасета
    if (dataset_input.size() != dataset_output.size()){
        cout << "ERROR! Training is not possible. \ndataset_input and dataset_output do not match in size. \n";
        return;
    }

    for (int i = 0; i < dataset_input.size(); ++i) {
        if ((dataset_input[i].size() != number_inputs) || dataset_output[i].size() != number_outputs){
            cout << "ERROR! Training is not possible. \nThe data does not correspond to the dimension of the neural network. \n";
            return;
        }
    }

    // Обучение TODO: Написать алгоритм обучения

    vector<float> dataset_result; // Значения выдающая нейросеть на датасете

    for (int ep = 1; ep <= number_epochs; ++ep) { // Эпохи

        for (int i = 0; i < dataset_input.size(); ++i) { // Перебираем датасеты
            dataset_result = run(dataset_input[i]);

        }


    }
}


void Neuron_network::print_weights() {
    for (int i = 0; i < network_layers.size(); ++i) {
        cout << i + 1 << ") ";
        network_layers[i].print();
    }
}
