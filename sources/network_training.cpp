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


Neuron_network Network_training::training(unsigned int numberEpochs, unsigned int step_for_epochs) {

    // Проверки датасета
    if (dataset_input.size() != dataset_output.size()){
        cout << "ERROR! Training is not possible. \ndataset_input and dataset_output do not match in size. \n";
    }

    for (int i = 0; i < dataset_input.size(); ++i) {
        if ((dataset_input[i].size() != number_inputs) || dataset_output[i].size() != number_outputs){
            cout << "ERROR! Training is not possible. \nThe data does not correspond to the dimension of the neural network. \n";
        }
    }

    Neuron_network best_network;
    float best_network_error = 1;


    // Инициализация 10 нейросетей и выбор лучшей
    for (int i = 0; i < step_for_epochs; ++i) {
        Neuron_network test_network(
                number_hidden_layers,
                neurons_per_layer,
                number_inputs,
                number_outputs
                );

        float max_test_network_error = 0;
        float test_network_error;
        for (int set = 0; set < dataset_input.size(); ++set) {
            vector<float> result_run = test_network.run(dataset_input[set]);

            test_network_error = mean_squared_error(dataset_output[set], result_run);

            if (max_test_network_error < test_network_error){
                max_test_network_error = test_network_error;
            }
        }

        cout << max_test_network_error << "\n";

        if (max_test_network_error < best_network_error){
            best_network = test_network;
            best_network_error = max_test_network_error;
        }
    }
    cout << "best: " << best_network_error << "\n";

    // Меняем веса у лучшей нейросети

//    for (int ep = 1; ep <= numberEpochs; ++ep) { // Эпохи
//
//
//
//        }
    return best_network;


    }


