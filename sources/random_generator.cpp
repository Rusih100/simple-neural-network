#include <random_generator.h>
#include <cmath>
#include <random>
#include <ctime>


Random::Random(int min, int max, unsigned int decimal_places) {
    this->min = min;
    this->max = max;

    range = max - min;
    degree = (int) pow(10, decimal_places);

    srand(time(NULL));
}

float Random::generate() {
    return (float)((rand() % (range * degree)) + (min * degree)) / (float)degree;
}


