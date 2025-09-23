#include <iostream>

class Printer {
  public:
    Printer() {
        std::cout << "Printed in constructor\n";
    }

    ~Printer() {
        std::cout << "Printed in destructor\n";
    }
};

Printer printer;

struct Placeholder {};

Placeholder placeholder = [](){
    std::cout << "Printed in lambda\n";
    return Placeholder{};
}();

int main() {
    return 0;
}
