#include <neuron_network.h>

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
