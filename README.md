# simple_neural_network
🧬 A simple evolutionary neural network in C++

## Description
Hi. This is a simple neural network model that is trained by evolution.
A neural network consists of two main classes [Network_training](https://github.com/Rusih100/simple_neural_network/blob/master/headers/network_training.h) and [Neuron_network](https://github.com/Rusih100/simple_neural_network/blob/master/headers/neuron_network.h).

## Example of creation
In this example, we will create a neural network that performs the XOR operation.

| x | y | XOR|
|:-:|:-:|:-:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Let's define data sets and expected results for these data sets.
```cpp
vector <vector<float>> dataset_input = {
            {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    vector <vector<float>> dataset_output = {
            {0}, {1}, {1}, {0}
    };
```

Create an instance of the Network_training class with the parameters:
2 hidden layers, 3 neurons on each hidden layer, 2 input neurons, 1 output neuron.

```cpp
Network_training Generate_network(dataset_input, dataset_output, 2, 3, 2, 1);
```

Let's train a neural network with these parameters for 100,000 epochs.
The method train() will return us a trained neural network

```cpp
Neuron_network XOR = Generate_network.training(100000);
```

Let's test the work of a neural network on a data set:

```cpp
cout << "Datasets result: \n";
    for (auto & set : dataset_input) {
        cout << "[ ";
        for (float i : set) {
            cout << i << " ";
        }
        cout << "] - ";
        cout << XOR.run(set)[0] << "\n";
    }
```

Result:
```
[ 0 0 ] - 2.19776e-17
[ 0 1 ] - 0.999999
[ 1 0 ] - 0.999999
[ 1 1 ] - 7.24945e-07
```


