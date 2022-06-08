#include <neuron_network.h>


Neuron_network::Neuron_network() {
    Neural_layer generate_L1(neurons_per_layer, number_inputs);
    Neural_layer generate_L2(neurons_per_layer, neurons_per_layer);
    Neural_layer generate_Out(number_outputs, neurons_per_layer);

    L1 = generate_L1;
    L2 = generate_L2;
    Out = generate_Out;
}

Matrix Neuron_network::run(const Matrix& input_values) {

    Matrix result = L1.run(input_values);
    result = L2.run(result);
    result = Out.run(result);
    return result;

}
