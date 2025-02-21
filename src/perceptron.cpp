#include "include/perceptron.hpp"

#include <iostream>
#include <vector>

Perceptron::Perceptron(const int &n_weights) {
    this->weights = std::vector<double>(n_weights);
}

bool Perceptron::output(const std::vector<double> &inputs) const {
    double total_sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
        total_sum += inputs[i] * this->weights[i];
    }
    return (total_sum + this->bias >= 0);
}

void Perceptron::update(const std::vector<double> &inputs, const bool &target) {
    const double error = target - this->output(inputs);
    this->errors.push_back(error);

    // Update bias
    double update = this->learning_rate * error;
    this->bias += update;

    // Update weights using the inputs
    for (int i = 0; i < inputs.size(); i++) {
        this->weights[i] += error * inputs[i];
    }
}

double Perceptron::loss() const {
    double sum = 0;
    for (const double &error : this->errors) {
        sum += error * error;
    }
    return sum / this->errors.size();
}

void Perceptron::setWeights(const std::vector<double> &newWeights) {
    this->bias = newWeights[0];

    // Skip i=0 because that is the bias
    for (int i = 1; i < newWeights.size(); i++) {
        this->weights[i - 1] = newWeights[i];
    }
}

void Perceptron::__str__() const {
    std::cout << "Bias: " << this->bias << std::endl;
    std::cout << "Weights:" << std::endl;
    for (const double &weight : this->weights) {
        std::cout << weight << std::endl;
    }
}
