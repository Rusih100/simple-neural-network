#ifndef LAB_08_RANDOM_GENERATOR_H
#define LAB_08_RANDOM_GENERATOR_H

class Random {
// Генерирует случайные число от min (включительно) до max (НЕ включительно)
// c decimal_places знаков после запятой

private:
    int min;
    int max;
    int range;

    int degree;

public:
    Random(int min, int max, unsigned int decimal_places = 0);

    float generate();
};

#endif
