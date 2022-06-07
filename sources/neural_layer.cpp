#include <neural_layer.h>
#include <cmath>

float Neural_layer::sigmoid_fx(float x) {
    return (float)(1 / (1 + pow(EXP, -x)));
}
