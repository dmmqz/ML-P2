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
 * This class represents a Perceptron in a layer. This class takes weights and
 * bias as input. Once the class is initialized, the Perceptron should first get
 * some training, using the `update` method. After it has been trained enough,
 * `output` can be called.
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
    bool output(const std::vector<double> &inputs) const;
    /**
     * @brief Updates the perceptron weights using a learning rule
     * @param inputs Inputs to update with
     * @param target Target that goes with the inputs
     */
    void update(const std::vector<double> &inputs, const bool &target);
    /**
     * @brief Calculates the MSE of the perceptron
     * @return double: Total MSE after updates
     */
    double loss() const;
    /**
     * @brief Sets bias and weights
     * @param weights A list of all the weights to set
     */
    void setWeights(const std::vector<double> &weights);
    /**
     * @brief Prints the perceptron attributes
     */
    void __str__() const;
};
