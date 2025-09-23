#include <iostream>
#include <format>

int main() {
    double epsilon;
    std::cin >> epsilon;

    double result = 0;
    int current_index = 1;
    double current = 1;
    while (current > epsilon) {
        result += current;
        current /= current_index;
        current_index++;
    }

    std::cout << std::format("{:.10}\n", result);
}
