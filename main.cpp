#include <iostream>
#include <vector>

#include <neural_layer.h>
#include <neuron_network.h>
#include <network_training.h>

#include <random_generator.h>

using namespace std;

int main() {
    srand(time(nullptr));

    Neuron_network Alpha(1, 1, 1, 1);
    Alpha.print_weights();
    Alpha.update_random_weight(1);
    Alpha.print_weights();


//    vector <vector<float>> dataset_input = {
//            {0, 0}, {0, 1}, {1, 0}, {1, 1}
//    };
//
//    vector <vector<float>> dataset_output = {
//            {0}, {1}, {1}, {0}
//    };
//
//
//    // Создание и тренировка нейросети
//    Network_training Generate_network(dataset_input, dataset_output, 1, 2);
//    Neuron_network XOR = Generate_network.training(10, 100);
//
//    // Проверка обученной нейросети
//    cout << "\nDatasets result: \n";
//    for (auto & set : dataset_input) {
//        cout << "[ ";
//        for (float i : set) {
//            cout << i << " ";
//        }
//        cout << "] - ";
//        cout << XOR.run(set)[0] << "\n";
//    }

    return 0;
}
