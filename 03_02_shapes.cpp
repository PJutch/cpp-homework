#include <iostream>
#include <numbers>
#include <cmath>

class Triangle {
    double a;
    double b;
    double c;

public:
    Triangle(double a, double b, double c) : a{a}, b{b}, c{c} {}

    double Perimeter() const {
        return a + b + c;
    }

    double Area() const {
        double halfPerimeter = Perimeter() / 2;
        return std::sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
    }
};

class Square {
    double side;

public:
    Square(double side) : side{side} {}

    double Perimeter() const {
        return 4 * side;
    }

    double Area() const {
        return side * side;
    }
};

class Circle {
    double radius;

public:
    Circle(double radius) : radius{radius} {}

    double Perimeter() const {
        return 2 * std::numbers::pi * radius;
    }

    double Area() const {
        return std::numbers::pi * radius * radius;
    }
};

int main() {
    Triangle triangle{1, 1, std::sqrt(2)};
    std::cout << triangle.Perimeter() << ' ' << triangle.Area() << '\n';
    
    Square square{3};
    std::cout << square.Perimeter() << ' ' << square.Area() << '\n';

    Circle circle{2};
    std::cout << circle.Perimeter() << ' ' << circle.Area() << '\n';
}
