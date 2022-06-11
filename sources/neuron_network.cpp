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
    Neural_layer generate_L1(neurons_per_layer, number_inputs);
    Neural_layer generate_L2(neurons_per_layer, neurons_per_layer);
    Neural_layer generate_Out(number_outputs, neurons_per_layer);

    L1 = generate_L1;
    L2 = generate_L2;
    Out = generate_Out;
}


vector<float> Neuron_network::run(const vector<float>& input_values) {

    vector<float> result(number_outputs);

    // Проверка входных данных
    if (input_values.size() != number_inputs){
        cout << "ERROR! The input data does not correspond to the dimension of the neural network.\n";
        return result;
    }

    // Вычисления
    Matrix calc_value = L1.run(Matrix(input_values));
    calc_value = L2.run(calc_value);
    calc_value = Out.run(calc_value);

    for (int i = 0; i < number_outputs; ++i) {
        result[i] = calc_value[0][i];
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


            // TODO: Написать стохастический градиентный спуск

        }


    }



}

