#include <iostream>
#include <cmath>

int main() {
    const double epsilon = 10e-6;

    double a, b, c;
    std::cin >> a >> b >> c;

    double d = b * b - 4 * a * c;
    
    if (d > epsilon) {
        double x1 = (-b + std::sqrt(d)) / 2 / a;
        double x2 = (-b - std::sqrt(d)) / 2 / a;

        std::cout << x1 << ' ' << x2 << '\n';
    } else if (d < -epsilon) {
        std::cout << "no solutions\n";
    } else {
        std::cout << -b / 2 / a << '\n';
    }
}
