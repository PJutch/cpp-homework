#include <iostream>
#include <cmath>
#include <numbers>

int main() {
    int number_index;
    std::cin >> number_index;

    double number = (std::pow(std::numbers::phi, number_index) - std::pow(-std::numbers::phi, -number_index)) / std::sqrt(5);
    std::cout << static_cast<int64_t>(std::round(number)) << '\n';
}