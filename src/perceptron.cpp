#include "include/perceptron.hpp"

#include <iostream>
#include <vector>

Perceptron::Perceptron(std::vector<double> weights, double bias) {
    this->weights = weights;
    this->bias = bias;
}

bool Perceptron::output(std::vector<bool> inputs) {
    double total_sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i]) {
            total_sum += this->weights[i];
        }
    }
    return (total_sum >= -this->bias);
}

void Perceptron::__str__() {
    std::cout << "Bias: " << this->bias << std::endl;
    std::cout << "Weights:" << std::endl;
    for (const double &weight : this->weights) {
        std::cout << weight << std::endl;
    }
}
