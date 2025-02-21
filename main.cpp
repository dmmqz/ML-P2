#include "test/include/parsedata.hpp"
#include <iostream>

int main() {
    std::vector<std::vector<double>> data = parseData("no_setosa.csv");
    std::vector<bool> targets{};

    for (std::vector<double> &row : data) {
        targets.push_back(row[4]);
        row.pop_back();

        for (const double &val : row) {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
