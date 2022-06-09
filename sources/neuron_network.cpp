#include <neuron_network.h>


Neuron_network::Neuron_network() {
    Neural_layer generate_L1(neurons_per_layer, number_inputs);
    Neural_layer generate_L2(neurons_per_layer, neurons_per_layer);
    Neural_layer generate_Out(number_outputs, neurons_per_layer);

    L1 = generate_L1;
    L2 = generate_L2;
    Out = generate_Out;
}

std::vector<float> Neuron_network::run(const std::vector<float>& input_values) {

    Matrix calc_value = L1.run(Matrix(input_values));
    calc_value = L2.run(calc_value);
    calc_value = Out.run(calc_value);

    std::vector<float> result(number_outputs);
    for (int i = 0; i < number_outputs; ++i) {
        result[i] = calc_value[0][i];
    }
    return result;
}
