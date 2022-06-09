#include <iostream>
#include <vector>

#include <neural_layer.h>
#include <neuron_network.h>


using namespace std;

int main() {
    srand(time(nullptr));

    Neuron_network Alpha;
    vector<float> dataset(2);

    while (true) {
        cin >> dataset[0] >> dataset[1];
        auto r =Alpha.run(dataset);

        for (int i = 0; i < 1; ++i) {
            cout << r[i] << "\n";
        }
    }

    return 0;
}
