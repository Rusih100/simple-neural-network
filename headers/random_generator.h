#ifndef LAB_08_RANDOM_GENERATOR_H
#define LAB_08_RANDOM_GENERATOR_H

class Random {
// Генерирует случайные число от min (включительно) до max (включительно)
// c decimal_places знаков после запятой

private:
    int min;
    int max;

    unsigned int decimal_places;

    // Генерирует цифру от 0 до 9
    static int generate_digit();

    // Переменные для функции generate
    long long int integer_part;
    long long int fractional_part;

public:
    Random(int min , int max, unsigned int decimal_places = 0);

    double generate();
};

#endif
