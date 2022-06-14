#include <network_training.h>

float Network_training::mean_squared_error(const vector<float>& x_true, const vector<float>& x) {
    // Среднеквадратичная ошибка

    // Проверка входных данных
    // Вернет -1, если размерности векторов не совпадают
    if (x_true.size() != x.size()) {
        cout << "ERROR. The dimensions of the vectors do not match. Return -1\n ";
        return -1;
    }

    float sum = 0;
    for (int i = 0; i < x.size(); ++i) {
        sum += (x_true[i] - x[i]) * (x_true[i] - x[i]);
    }
    return sum / (float)x.size();
}


Network_training::Network_training(const vector <vector<float>> &dataset_input,
                                   const vector <vector<float>> &dataset_output,
                                   unsigned int number_epochs,

                                   unsigned int hidden_layers_n,
                                   unsigned int neurons_per_layer_n,
                                   unsigned int inputs_n,
                                   unsigned int outputs_n
                                   ) {

    // Инициализация параметров генерируемых нейросетей
    this->number_hidden_layers = hidden_layers_n;
    this->neurons_per_layer = neurons_per_layer_n;
    this->number_inputs = inputs_n;
    this->number_outputs = outputs_n;

    // Инициализациия датасетов
    this->dataset_input = dataset_input;
    this->dataset_output = dataset_output;

    // Инициализация колличества эпох обучения
    this->number_epochs = number_epochs;

}


void Network_training::training() {

    // Проверки датасета
    if (dataset_input.size() != dataset_output.size()){
        cout << "ERROR! Training is not possible. \ndataset_input and dataset_output do not match in size. \n";
        return;
    }

    for (int i = 0; i < dataset_input.size(); ++i) {
        if ((dataset_input[i].size() != number_inputs) || dataset_output[i].size() != number_outputs){
            cout << "ERROR! Training is not possible. \nThe data does not correspond to the dimension of the neural network. \n";
            return;
        }
    }

    vector<float> dataset_result; // Значения выдающая нейросеть на датасете

    for (int ep = 1; ep <= number_epochs; ++ep) { // Эпохи



        }


    }


