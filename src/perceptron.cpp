#include "include/perceptron.hpp"

#include <iostream>
#include <vector>

Perceptron::Perceptron(const int &n_weights) {
    this->weights = std::vector<double>(n_weights);
}

bool Perceptron::output(const std::vector<bool> &inputs) {
    double total_sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i]) {
            total_sum += this->weights[i];
        }
    }
    return (total_sum >= -this->bias);
}

void Perceptron::update(const std::vector<bool> &inputs, const bool &target) {
    const double error = target - this->output(inputs);
    this->errors.push_back(error);

    // Update bias (no input)
    this->bias += this->learning_rate * error;

    // Update weights using the inputs
    for (int i = 0; i < inputs.size(); i++) {
        this->weights[i] += this->learning_rate * error * inputs[i];
    }
}

double Perceptron::loss() {
    double sum = 0;
    for (const double &error : this->errors) {
        sum += error * error;
    }
    return sum / this->errors.size();
}

void Perceptron::__str__() {
    std::cout << "Bias: " << this->bias << std::endl;
    std::cout << "Weights:" << std::endl;
    for (const double &weight : this->weights) {
        std::cout << weight << std::endl;
    }
}
