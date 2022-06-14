#include <neural_layer.h>
#include <cmath>

float Neural_layer::sigmoid_fx(float x) {
    return (float)(1 / (1 + pow(EXP, -x)));
}


Neural_layer::Neural_layer() {
    this->number_neurons = 0;
    this->number_inputs = 0;
    Matrix generate_weights;
    weights = generate_weights;
}


Neural_layer::Neural_layer(unsigned int number_neurons, unsigned int number_inputs) {
    this->number_neurons = number_neurons;
    this->number_inputs = number_inputs;

    Matrix generate_weights(this->number_inputs, this->number_neurons);
    generate_weights.random_fill(-3, 3, 3);

    weights = generate_weights;
}


Matrix Neural_layer::run(Matrix input_values) {

    Matrix result = input_values * weights;
    for (int i = 0; i < number_neurons; ++i) {
        result[0][i] = sigmoid_fx(result[0][i]);
    }

    return result;
}


Neural_layer& Neural_layer::operator=(const Neural_layer& other) {
    if (this == &other){
        return *this;
    }
    number_neurons = other.number_neurons;
    number_inputs = other.number_inputs;
    weights = other.weights;
    return *this;
}


void Neural_layer::print() {
    cout << "Weights: \n";
    weights.print();
    cout << "\n";
}



