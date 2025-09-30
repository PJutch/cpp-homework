#include <iostream>
#include <iomanip>

struct Node {
    int value;
    Node* next = nullptr;
};

class List {
    Node* head = nullptr;
    Node* tail = nullptr;

    Node* before_tail() {
        Node* current = head;
        while (current != nullptr && current->next != tail) {
            current = current->next;
        }
        return current;
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
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << ' ';
            current = current->next;
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
        
        if (Node* before_tail_ = before_tail()) {
            before_tail_->next = nullptr;
        }

        delete old_tail;
    }

    Node* get(int index) {
        Node* current = head;
        while (index > 0) {
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

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.show();
    std::cout << std::boolalpha << list.empty() << '\n';

    list.pop_front();
    list.push_back(5);
    list.show();

    list.pop_back();
    list.push_front(7);
    list.show();
}
