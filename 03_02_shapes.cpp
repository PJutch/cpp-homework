#include <iostream>
#include <numbers>
#include <cmath>

class Triangle {
    double a;
    double b;
    double c;

public:
    Triangle(double a, double b, double c) : a{a}, b{b}, c{c} {}

    double perimeter() const {
        return a + b + c;
    }

    double area() const {
        double half_perimeter = perimeter() / 2;
        return std::sqrt(half_perimeter * (half_perimeter - a) * (half_perimeter - b) * (half_perimeter - c));
    }
};

class Square {
    double side;

public:
    Square(double side) : side{side} {}

    double perimeter() const {
        return 4 * side;
    }

    double area() const {
        return side * side;
    }
};

class Circle {
    double radius;

public:
    Circle(double radius) : radius{radius} {}

    double perimeter() const {
        return 2 * std::numbers::pi * radius;
    }

    double area() const {
        return std::numbers::pi * radius * radius;
    }
};

int main() {
    Triangle triangle{1, 1, std::sqrt(2)};
    std::cout << triangle.perimeter() << ' ' << triangle.area() << '\n';
    
    Square square{3};
    std::cout << square.perimeter() << ' ' << square.area() << '\n';

    Circle circle{2};
    std::cout << circle.perimeter() << ' ' << circle.area() << '\n';
}
