#include <network_training.h>

float Network_training::mean_squared_error(const vector<float>& x_true, const vector<float>& x) {
    // Проверка входных данных

    // Проверка размерности векторов
    if (x_true.size() != x.size()) {
        throw invalid_argument("The dimensions of the vectors do not match \n");
    }

    // Проверка на пустоту
    if (x_true.empty()){
        throw invalid_argument("An empty vector was passed");
    }

    float sum = 0;
    for (int i = 0; i < x.size(); ++i) {
        sum += (x_true[i] - x[i]) * (x_true[i] - x[i]);
    }
    return sum / (float)x.size();
}


Network_training::Network_training(const vector <vector<float>> &dataset_input,
                                   const vector <vector<float>> &dataset_output,
                                   const Neuron_network& network
                                   ) {
    // Проверки датасетов

    // Проверка на совпадение размерностей входных и выходных данных
    if (dataset_input.size() != dataset_output.size()){
        throw invalid_argument("Dataset_input and dataset_output do not match in size. \n");
    }

    for (int i = 0; i < dataset_input.size(); ++i) {
        if ((dataset_input[i].size() != network.number_inputs) || dataset_output[i].size() != network.number_outputs){
            throw invalid_argument("The data does not correspond to the dimension of the neural network. \n");
        }
    }

    cout << "The beginning of neural network training.\n";

    // Инициализация нейросети
    this->network = network;

    // Инициализациия датасетов
    this->dataset_input = dataset_input;
    this->dataset_output = dataset_output;

}

void Network_training::update_random_weight(Neuron_network& network, unsigned int decimal_places, unsigned int max_deviation) {

    // Выбираем случайный слой
    int layer_index = random_int(0, (int)network.network_layers.size() - 1);

    // Узнаем размерности матрицы для выбора случайного веса
    int max_row_index = (int)network.network_layers[layer_index].number_inputs - 1;
    int max_colomn_index = (int)network.network_layers[layer_index].number_neurons - 1;

    // Выбираем случайнык вес матрице весов
    int row = random_int(0, max_row_index);
    int colomn = random_int(0, max_colomn_index);

    // Генерируем изменяемое число
    double num = ((double)random_int(1, 1 + (int)max_deviation) /
                  pow(10, decimal_places)) * pow(-1, random_int(0, 1));

    // Меняем число
    network.network_layers[layer_index].weights[row][colomn] += (float)num;
}

Neuron_network Network_training::training(unsigned int number_epochs) {

    // Стартовая нейросеть, которая будет мутировать в лучшую
    Neuron_network best_network = network;
    float best_network_error = 1;

    // Меняем веса у лучшей нейросети
    for (int ep = 1; ep <= number_epochs; ++ep) { // Эпохи

        // Копируем лучшую сеть
        Neuron_network test_network = best_network;

        // Качаем веса
        update_random_weight(test_network, random_int(0,3), random_int(0, 5));

        float avg_test_network_error = 0;   // Средняя ошибка из датасетов
        float set_error;                    // Ошибка датасета

        // Прогоняем датасеты и считаем среднюю ошибку датасетов
        for (int set = 0; set < dataset_input.size(); ++set) {

            vector<float> result_run = test_network.run(dataset_input[set]);
            set_error = mean_squared_error(dataset_output[set], result_run);
            avg_test_network_error += set_error;
        }
        avg_test_network_error = avg_test_network_error / (float)dataset_input.size();

        // Если сеть стала лучше, принимаем конфигурацию
        if (avg_test_network_error < best_network_error){
            best_network = test_network;
            best_network_error = avg_test_network_error;
        }
    }
    cout << "The neural network is trained. Network error: " << best_network_error << "\n";

    return best_network;
    }


