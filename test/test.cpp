#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"

#include "../src/include/perceptron.hpp"
#include "include/parsedata.hpp"

TEST_CASE("Test AND-gate") {
    Perceptron andGate = Perceptron(2);

    for (int i = 0; i < 100; i++) {
        andGate.update({0, 0}, 0);
        andGate.update({1, 0}, 0);
        andGate.update({0, 1}, 0);
        andGate.update({1, 1}, 1);
    }

    REQUIRE(!andGate.output({0, 0}));
    REQUIRE(!andGate.output({1, 0}));
    REQUIRE(!andGate.output({0, 1}));
    REQUIRE(andGate.output({1, 1}));
}

// This test should fail
TEST_CASE("Test XOR-gate") {
    Perceptron xorGate = Perceptron(2);

    for (int i = 0; i < 100; i++) {
        xorGate.update({0, 0}, 0);
        xorGate.update({1, 0}, 1);
        xorGate.update({0, 1}, 1);
        xorGate.update({1, 1}, 0);
    }

    CHECK(!xorGate.output({0, 0}));
    CHECK(xorGate.output({1, 0}));
    CHECK(xorGate.output({0, 1}));
    CHECK(!xorGate.output({1, 1}));
    /* Final values:
     * Bias: 0.1
     * Weights:
     * 2.77556e-17
     * -0.1
     */
}

TEST_CASE("Test Setosa vs. Versicolor") {
    std::vector<std::vector<double>> data = parseData("no_virginica.csv");

    std::vector<std::vector<double>> inputs{};
    std::vector<bool> targets{};

    for (int i = 0; i < data.size(); i++) {
        std::vector<double> row = data[i];
        targets.push_back(row[4]);
        row.pop_back();
        inputs.push_back(row);
    }

    Perceptron p = Perceptron(4);

    // epochs = 100
    for (int k = 0; k < 100; k++) {
        for (int i = 0; i < targets.size(); i++) {
            p.update(inputs[i], targets[i]);
        }
    }

    std::vector<bool> outputs{};
    for (const std::vector<double> &input : inputs) {
        outputs.push_back(p.output(input));
    }

    REQUIRE(outputs == targets);
    std::cout << "Setosa vs. Versicolor perceptron:" << std::endl;
    p.__str__();
}

// NOTE: this tests fails, because it predicts ~31 wrong. This still
// happens if specific columns are chosen.
// This is because Versicolor and Virginica are quite similar
// See: https://debuggercafe.com/wp-content/uploads/2019/04/feature_plot-1.png
TEST_CASE("Test Versicolor vs. Virginica") {
    std::vector<std::vector<double>> data = parseData("no_setosa.csv");

    std::vector<std::vector<double>> inputs{};
    std::vector<bool> targets{};

    for (int i = 0; i < data.size(); i++) {
        std::vector<double> row = data[i];
        targets.push_back(row[4]);
        row.pop_back();
        inputs.push_back(row);
    }

    Perceptron p = Perceptron(4);

    // epochs = 100
    for (int k = 0; k < 100; k++) {
        for (int i = 0; i < targets.size(); i++) {
            p.update(inputs[i], targets[i]);
        }
    }

    std::vector<bool> outputs{};
    for (const std::vector<double> &input : inputs) {
        outputs.push_back(p.output(input));
    }

    // Fails
    CHECK(outputs == targets);
    std::cout << "Versicolor vs. Virginica perceptron:" << std::endl;
    p.__str__();
}
