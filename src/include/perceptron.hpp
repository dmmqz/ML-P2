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
    double bias;

  public:
    /**
     * @brief Constructs a perceptron with weights and a bias
     * @param weights The weights for each input
     * @param bias The bias for this perceptron
     */
    Perceptron(std::vector<double> weights, double bias);
    /**
     * @brief Method to get an output given inputs
     * @param inputs Inputs for this perceptron
     * @return bool: Output given the inputs
     */
    bool output(std::vector<bool> inputs);
    /**
     * @brief Prints the perceptron attributes
     */
    void __str__();
};
