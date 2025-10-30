#include <cmath>
#include <iostream>
#include <numbers>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;

    virtual double perimeter() const = 0;
    virtual double area() const = 0;
};

class Triangle : public Shape {
    double a;
    double b;
    double c;

public:
    Triangle(double a, double b, double c) : a{a}, b{b}, c{c} {}

    double perimeter() const override final { return a + b + c; }

    double area() const override final {
        double half_perimeter = perimeter() / 2;
        return std::sqrt(half_perimeter * (half_perimeter - a) *
                         (half_perimeter - b) * (half_perimeter - c));
    }
};

class Square final : public Shape {
    double side;

public:
    Square(double side) : side{side} {}

    double perimeter() const override { return 4 * side; }

    double area() const override { return side * side; }
};

class Circle final : public Shape {
    double radius;

public:
    Circle(double radius) : radius{radius} {}

    double perimeter() const override { return 2 * std::numbers::pi * radius; }

    double area() const override { return std::numbers::pi * radius * radius; }
};

int main() {
    std::vector<Shape*> shapes{new Triangle{1, 1, std::sqrt(2)}, new Square{3},
                               new Circle{2}};
    for (Shape* shape : shapes) {
        std::cout << shape->perimeter() << ' ' << shape->area() << '\n';
    }
}
