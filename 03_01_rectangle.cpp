#include <iostream>
#include <vector>

struct Rectangle {
    double left;
    double right;
    double up;
    double down;

    double area() const {
        if (right > left && down > up) {
            return (right - left) * (down - up);
        } else {
            return 0;
        }
    }

    void print() const {
        std::cout << "{ " << left << ", " << right << ", " << up << ", " << down << " }";
    }
};

Rectangle intersection(Rectangle rectangle1, Rectangle rectangle2) {
    return {std::max(rectangle1.left, rectangle2.left),
            std::min(rectangle1.right, rectangle2.right),
            std::max(rectangle1.up, rectangle2.up),
            std::min(rectangle1.down, rectangle2.down)};
}

Rectangle intersection(const std::vector<Rectangle>& rectangles) {
    if (rectangles.empty()) {
        return {};
    }

    Rectangle result = rectangles.front();
    for (Rectangle rectangle : rectangles) {
        result = intersection(result, rectangle);
    }
    return result;
}

double intersection_area(const std::vector<Rectangle>& rectangles) {
    return intersection(rectangles).area();
}

Rectangle bounding_box(Rectangle rectangle1, Rectangle rectangle2) {
    return {std::min(rectangle1.left, rectangle2.left),
            std::max(rectangle1.right, rectangle2.right),
            std::min(rectangle1.up, rectangle2.up),
            std::max(rectangle1.down, rectangle2.down)};
}

Rectangle bounding_box(const std::vector<Rectangle>& rectangles) {
    if (rectangles.empty()) {
        return {};
    }

    Rectangle result = rectangles.front();
    for (Rectangle rectangle : rectangles) {
        result = bounding_box(result, rectangle);
    }
    return result;
}

int main() {
    std::vector<Rectangle> rectangles{{0, 4, 0, 2}, {1, 5, 1, 3}};

    intersection(rectangles).print();
    std::cout << '\n';

    std::cout << intersection_area(rectangles) << '\n';

    bounding_box(rectangles).print();
    std::cout << '\n';
}
