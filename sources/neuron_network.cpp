#include <neuron_network.h>

Neuron_network::Neuron_network(const Neuron_network &other) {
    this->number_hidden_layers = other.number_hidden_layers;
    this->neurons_per_layer = other.neurons_per_layer;
    this->number_inputs = other.number_inputs;
    this->number_outputs = other.number_outputs;
    this->network_layers = other.network_layers;
}


Neuron_network::Neuron_network(
        unsigned int hidden_layers_n,
        unsigned int neurons_per_layer_n,
        unsigned int inputs_n,
        unsigned int outputs_n
        ) {

    this->number_hidden_layers = hidden_layers_n;
    this->neurons_per_layer = neurons_per_layer_n;
    this->number_inputs = inputs_n;
    this->number_outputs = outputs_n;

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


void Neuron_network::print_weights() {
    for (int i = 0; i < network_layers.size(); ++i) {
        cout << i + 1 << ") ";
        network_layers[i].print();
    }
}


void Neuron_network::update_random_weight(unsigned int decimal_places) {

    // Выбираем случайный слой
    int layer_i = (int)Random(0, (int)network_layers.size() - 1).generate();

    // Узнаем размерности матрицы для выбора случайного веса
    int max_row_i = (int)network_layers[layer_i].number_inputs - 1;
    int max_colomn_i = (int)network_layers[layer_i].number_neurons - 1;

    // Выбираем случайнык вес
    int row = (int)Random(0, max_row_i).generate();
    int colomn = (int)Random(0, max_colomn_i).generate();

    // Генерируем изменяемое число
    Random G(1, 5);
    double num = pow(-1, G.generate()) * (G.generate() / pow(10, decimal_places));

    // TODO Найти деление на 0, оптимизировать

    // Меняем число
    network_layers[layer_i].weights[row][colomn] += (float)num;
}



Neuron_network &Neuron_network::operator=(const Neuron_network &other) {

    if (this == &other){
        return *this;
    }

    this->number_hidden_layers = other.number_hidden_layers;
    this->neurons_per_layer = other.neurons_per_layer;
    this->number_inputs = other.number_inputs;
    this->number_outputs = other.number_outputs;
    this->network_layers = other.network_layers;

    return *this;
}


