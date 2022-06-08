#include <neural_layer.h>
#include <cmath>

float Neural_layer::sigmoid_fx(float x) {
    return (float)(1 / (1 + pow(EXP, -x)));
}

Neural_layer::Neural_layer(unsigned int number_of_neurons, unsigned int number_of_inputs) {
    this->number_of_neurons = number_of_neurons;
    this->number_of_inputs = number_of_inputs;

    Matrix generate_weights(this->number_of_inputs, this->number_of_neurons);
    generate_weights.random_fill(0, 1, 2);

    weights = generate_weights;
}

Matrix Neural_layer::run(Matrix input_values) {

    Matrix result = input_values * weights;
    for (int i = 0; i < number_of_neurons; ++i) {
        result[0][i] = sigmoid_fx(result[0][i]);
    }

    return result;
}



