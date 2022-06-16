#ifndef LAB_08_RANDOM_GENERATOR_H
#define LAB_08_RANDOM_GENERATOR_H


// Генерирует цифру от 0 до 9
int random_digit();


int random_int(int min, int max);


// Генерирует случайное число с плавающей точкой от min (включительно) до max (включительно)
double random_double(int min , int max, unsigned int decimal_places = 0);



#endif
