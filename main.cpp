#include <iostream>
#include <vector>

#include <neural_layer.h>
#include <neuron_network.h>
#include <network_training.h>


using namespace std;

int main() {
    srand(time(nullptr));

    vector <vector<float>> dataset_input = {
            {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    vector <vector<float>> dataset_output = {
            {1}, {1}, {1}, {1}
    };

    Network_training NetT(dataset_input, dataset_output, 1, 2);
    auto R = NetT.training(10, 100);

    cout << "\n\n";
    cout << R.run(dataset_input[0])[0] << "\n";
    cout << R.run(dataset_input[1])[0] << "\n";
    cout << R.run(dataset_input[2])[0] << "\n";
    cout << R.run(dataset_input[3])[0] << "\n\n";

    R.print_weights();

//    Neuron_network Alpha;
//    Alpha.print_weights();


//
//    vector<float> dataset(2);
//
//    while (true) {
//        cin >> dataset[0] >> dataset[1];
//        auto r = Alpha.run(dataset);
//
//        for (int i = 0; i < 1; ++i) {
//            cout << r[i] << "\n";
//        }
//    }
//
//    return 0;
}
