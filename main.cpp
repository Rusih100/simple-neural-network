#include <iostream>
#include <vector>

#include <neuron_network.h>
#include <network_training.h>

using namespace std;

void XOR_network(){
    // XOR датасет
    vector <vector<float>> dataset_input = {
            {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    vector <vector<float>> dataset_output = {
            {0}, {1}, {1}, {0}
    };

    // Создание и тренировка нейросети
    Neuron_network XOR(2, 2, 2, 1);

    Network_training Training_network(dataset_input, dataset_output, XOR);
    XOR = Training_network.training(100000);

    // Проверка обученной нейросети
    cout << "\nDatasets result: \n";
    for (auto & set : dataset_input) {
        cout << "[ ";
        for (float i : set) {
            cout << i << " ";
        }
        cout << "] - ";
        cout << XOR.run(set)[0] << "\n";
    }
    cout << "\n";

    XOR.print_weights();
}

int main() {
    srand(time(nullptr));
    XOR_network();

    return 0;
}
