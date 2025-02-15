#include "src/include/perceptron.hpp"
#include <iostream>

int main() {
    // OR gate
    Perceptron orGate = Perceptron(2);
    for (int i = 0; i < 100; i++) {
        orGate.update({0, 0}, 0);
        orGate.update({1, 0}, 1);
        orGate.update({0, 1}, 1);
        orGate.update({1, 1}, 1);
    }

    std::cout << "OR gate:" << std::endl;
    std::cout << orGate.output({0, 0}) << std::endl;
    std::cout << orGate.output({1, 0}) << std::endl;
    std::cout << orGate.output({0, 1}) << std::endl;
    std::cout << orGate.output({1, 1}) << std::endl;
    std::cout << "MSE: " << orGate.loss() << std::endl;

    // NOT gate
    Perceptron notGate = Perceptron(1);

    for (int i = 0; i < 100; i++) {
        notGate.update({0}, 1);
        notGate.update({1}, 0);
    }

    std::cout << "NOT gate:" << std::endl;
    std::cout << notGate.output({0}) << std::endl;
    std::cout << notGate.output({1}) << std::endl;
    std::cout << "MSE: " << notGate.loss() << std::endl;

    return 0;
}
