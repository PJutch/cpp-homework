#include <iostream>

int main() {
    char c;
    std::cin >> c;

    switch (c) {
    case 'a'...'z':
        std::cout << "small letter\n";
        break;
    case 'A'...'Z':
        std::cout << "capital letter\n";
        break;
    case '0'...'9':
        std::cout << "digit\n";
        break;
    case '!'...'/':
    case ':'...'@':
    case '['...'`':
    case '{'...'~':
        std::cout << "punctuation\n";
        break;
    default:
        std::cout << "some other character\n";
        break;
    }
}
