#include <iostream>
#include <numeric>

int gcd(int a, int b) {
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    const int MAX_TESTED = 1000;

    for (int a = 1; a < MAX_TESTED; ++a) {
        for (int b = 1; b < MAX_TESTED; ++b) {
            int expected_gcd = std::gcd(a, b);
            int actual_gcd = gcd(a, b);
            if (actual_gcd != expected_gcd) {
                std::cout << "Expected gcd: " << expected_gcd << ", actual gcd: " << actual_gcd << '\n';
            }

            int expected_lcm = std::lcm(a, b);
            int actual_lcm = lcm(a, b);
            if (actual_lcm != expected_lcm) {
                std::cout << "Expected lcm: " << expected_lcm << ", actual lcm: " << actual_lcm << '\n';
            }
        }
    }
}