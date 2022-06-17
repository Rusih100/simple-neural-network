# simple_neural_network
🧬 A simple evolutionary neural network in C++

## Description
Hi. This is a simple neural network model that is trained by evolution.  
A neural network consists of two main classes [Network_training](https://github.com/Rusih100/simple_neural_network/blob/master/headers/network_training.h) and [Neuron_network](https://github.com/Rusih100/simple_neural_network/blob/master/headers/neuron_network.h).  


## Example of creating a neural network
In this example, we will create a neural network that performs the XOR operation.

| x | y | XOR|
|:-:|:-:|:-:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Let's define datasets and expected results for these datasets.  
The neural network takes a vector of values as input and returns the result as a vector.

```cpp
vector <vector<float>> dataset_input = {
            {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

vector <vector<float>> dataset_output = {
            {0}, {1}, {1}, {0}
    };
```

Create an instance of the Network_training class with the parameters:  
2 hidden layers (hidden_layers_n), 3 neurons on each hidden layer (neurons_per_layer_n), 2 input neurons (inputs_n), 1 output neuron (outputs_n).

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

Results:
```
Datasets result:
[ 0 0 ] - 1.13952e-17
[ 0 1 ] - 1
[ 1 0 ] - 1
[ 1 1 ] - 9.37329e-10
```

The weights of the neural network can be viewed using the method print_weights():
```
1) Weights:
-27.697 8.582 -16.824
8.101 -27.766 -15.757

2) Weights:
-7.891 -5.387 6.158
23.374 -7.467 9.219
7.007 14.167 -26.493

3) Weights:
-0.27
-58.941
17.635
```


