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

    // Проверка входных данных

    // Проверка количества входных нейронов
    if (inputs_n == 0){
        throw invalid_argument("The number of input neurons must be greater than zero. \n");
    }

    // Проверка количества выходных нейронов
    if (outputs_n == 0){
        throw invalid_argument("The number of output neurons must be greater than zero. \n");
    }

    // Проверка количества скрытых нейронов
    if (hidden_layers_n != 0 && neurons_per_layer_n == 0){
        throw invalid_argument("The number of neurons on the hidden layer must be greater than zero if there is a hidden layer. \n");
    }

    this->number_hidden_layers = hidden_layers_n;
    this->neurons_per_layer = neurons_per_layer_n;
    this->number_inputs = inputs_n;
    this->number_outputs = outputs_n;

    // Если есть скрытый слой
    if (number_hidden_layers != 0){

        Neural_layer input_Layer(neurons_per_layer, number_inputs);
        network_layers.push_back(input_Layer);

        for (int i = 0; i < number_hidden_layers - 1; ++i) {
            Neural_layer hidden_Layer(neurons_per_layer, neurons_per_layer);
            network_layers.push_back(hidden_Layer);
        }

        Neural_layer output_Layer(number_outputs, neurons_per_layer);
        network_layers.push_back(output_Layer);

    // Если нет скрытых слоев
    } else {
        Neural_layer input_Layer(number_outputs, number_inputs);
        network_layers.push_back(input_Layer);
    }

}


vector<float> Neuron_network::run(const vector<float>& input_values) {

    // Проверка входных данных
    if (input_values.size() != number_inputs){
        throw invalid_argument("The input data does not correspond to the dimension of the neural network.\n");
    }

    // Вычисления
    Matrix temp(input_values);

    for (auto & layer : network_layers) {
        temp = layer.run(temp);
    }

    vector<float> result(number_outputs); // Результат

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


