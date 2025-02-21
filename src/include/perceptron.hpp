/**
 * @file perceptron.hpp
 * @brief Define Perceptron class
 * @author Dylan McGivern
 */
#pragma once

#include <vector>

/**
 * @class Perceptron
 * @brief Perceptron with 1 or more inputs
 *
 * This class represents a perceptron in a layer. This class takes weights and
 * bias as input. Once the class is initialized, output can be called. The
 * amount of inputs must be as much or less than the amount of weights.
 */
class Perceptron {
  private:
    std::vector<double> weights;
    double bias = -1;
    const double learning_rate = 0.1;
    std::vector<double> errors;

  public:
    /**
     * @brief Constructs a perceptron with weights and a bias
     * @param n_weights Number of weights
     */
    Perceptron(const int &n_weights);
    /**
     * @brief Method to get an output given inputs
     * @param inputs Inputs for this perceptron
     * @return bool: Output given the inputs
     */
    bool output(const std::vector<double> &inputs);
    void update(const std::vector<double> &inputs, const bool &target);
    double loss();
    /**
     * @brief Prints the perceptron attributes
     */
    void __str__();
};
