#include <cassert>
#include <iostream>

class Entity {
    friend class Attorney;

    static void test1() { std::cout << "Test 1\n"; }

    static void test2() { std::cout << "Test 2\n"; }

    // ... lots of code ...

    static void do_not_test() { assert(false); }
};

class Attorney {
    friend class Client1;
    friend class Client2;

    static void test1() { Entity::test1(); }

    static void test2() { Entity::test2(); }
};

class Client1 {
public:
    static void test() { Attorney::test1(); }
    
    // ... lots of code ...
};

class Client2 {
public:
    static void test() { Attorney::test2(); }

    // ... lots of code ...
};

int main() {
    Client1::test();
    Client2::test();
    // Entity::do_not_test(); // error: inacessible
}
