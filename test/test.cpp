#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"

#include "../src/include/perceptron.hpp"

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
