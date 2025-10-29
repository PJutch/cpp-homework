#include <cmath>
#include <iostream>
#include <numbers>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;

    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Shape {
    double a;
    double b;
    double c;

public:
    Triangle(double a, double b, double c) : a{a}, b{b}, c{c} {}

    double Perimeter() const override final { return a + b + c; }

    double Area() const override final {
        double halfPerimeter = Perimeter() / 2;
        return std::sqrt(halfPerimeter * (halfPerimeter - a) *
                         (halfPerimeter - b) * (halfPerimeter - c));
    }
};

class Square final : public Shape {
    double side;

public:
    Square(double side) : side{side} {}

    double Perimeter() const override { return 4 * side; }

    double Area() const override { return side * side; }
};

class Circle final : public Shape {
    double radius;

public:
    Circle(double radius) : radius{radius} {}

    double Perimeter() const override { return 2 * std::numbers::pi * radius; }

    double Area() const override { return std::numbers::pi * radius * radius; }
};

int main() {
    std::vector<Shape*> shapes{new Triangle{1, 1, std::sqrt(2)}, new Square{3},
                               new Circle{2}};
    for (Shape* shape : shapes) {
        std::cout << shape->Perimeter() << ' ' << shape->Area() << '\n';
    }
}
