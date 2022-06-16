#include <random_generator.h>
#include <cmath>


int random_digit() {
    return rand() % 10;
}


int random_int(int min, int max){

    // Проверка на min и max
    int _min = (min < max) ? min : max;
    int _max = (max > min) ? max : min;

    return rand() % (_max - _min + 1) + _min;
}


double random_double(int min , int max, unsigned int decimal_places){

    // Проверка на min и max
    int _min = (min < max) ? min : max;
    int _max = (max > min) ? max : min;

    // Генерируем целую часть числа
    long long int integer_part = rand() % (_max - _min) + _min;

    // Генерируем дробную часть числа
    long long int fractional_part = 0;
    for (int i = 0; i <= decimal_places; ++i) {
        fractional_part += random_digit() * (long long int)pow(10, i);
    }

    double result = round((double)fractional_part / 10);
    result = (double)integer_part + result / pow(10, decimal_places);

    return result;

}

