#include <random_generator.h>
#include <cmath>


int Random::generate_digit() {
    return rand() % 10;
}


Random::Random(int min, int max, unsigned int decimal_places) {

    // Проверка на min и max
    this->min = (min < max) ? min : max;
    this->max = (max > min) ? max : min;

    this->decimal_places = decimal_places;
}


double Random::generate() {

    // Генерируем целую часть числа
    integer_part = rand() % (max - min) + min;
    
    // Генерируем дробную часть числа
    fractional_part = 0;
    for (int i = 0; i <= decimal_places; ++i) {
        fractional_part += generate_digit() * (long long int)pow(10, i);
    }

    double result = round((double)fractional_part / 10);
    result = (double)integer_part + result / pow(10, decimal_places);

    return result;

}







