#include <iostream>
#include <iomanip>

struct Node {
    int value;
    Node* next = nullptr;
};

class List {
    Node* head = nullptr;
    Node* tail = nullptr;

    size_t size() const {
        size_t result = 0;
        for (Node* current = head; current != nullptr; current = current->next) {
            ++result;
        }
        return result;
    }
public:
    List() = default;

    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    bool empty() const {
        return  head == nullptr;
    }

    void show() const {
        for (Node* current = head; current != nullptr; current = current->next) {
            std::cout << current->value << ' ';
        }
        std::cout << '\n';
    }

    void push_front(int value) {
        head = new Node{value, head};
        if (tail == nullptr) {
            tail = head;
        }
    }

    void push_back(int value) {
        Node* old_tail = tail;
        tail = new Node{value};
        
        if (old_tail != nullptr) {
            old_tail->next = tail;
        }

        if (head == nullptr) {
            head = tail;
        }
    }

    void pop_front() {
        Node* old_head = head;
        
        if (tail == head) {
            tail = nullptr;
        }
        
        if (head != nullptr) {
            head = head->next;
        }

        delete old_head;
    }

    void pop_back() {
        Node* old_tail = tail;
        
        if (head == tail) {
            head = nullptr;
        }
        
        if (Node* before_tail = get(size() - 2)) {
            before_tail->next = nullptr;
        }

        delete old_tail;
    }

    Node* get(int index) {
        if (index < 0) {
            return nullptr;
        }

        Node* current = head;
        while (index > 0 && current != nullptr) {
            current = current->next;
            --index;
        }
        return current;
    }
};

int main() {
    List list{};
    list.show();
    std::cout << std::boolalpha << list.empty() << '\n';
    std::cout << std::hex << list.get(0) << '\n';

    list.pop_back();
    list.pop_front();

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.show();
    std::cout << std::boolalpha << list.empty() << '\n';
    std::cout << std::hex << list.get(0) << '\n';

    list.pop_front();
    list.push_back(5);
    list.show();

    list.pop_back();
    list.push_front(7);
    list.show();

    while (!list.empty()) {
        list.pop_back();
    }
    std::cout << std::boolalpha << list.empty() << '\n';

    list.push_front(1);
    list.show();
    std::cout << std::boolalpha << list.empty() << '\n';
}
