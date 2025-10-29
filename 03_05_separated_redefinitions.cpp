#include <iostream>

class Entity_v1 {
public:
    virtual ~Entity_v1() = default;
    virtual void test() = 0;
};

class Entity_v2 {
public:
    virtual ~Entity_v2() = default;
    virtual void test() = 0;
};

class Adapter_v1 : public Entity_v1 {
public:
    virtual void test_v1() = 0;

    void test() final { test_v1(); }
};

class Adapter_v2 : public Entity_v2 {
public:
    virtual void test_v2() = 0;

    void test() final { test_v2(); }
};

class Client : public Adapter_v1, public Adapter_v2 {
public:
    void test_v1() override { std::cout << "Test v1!\n"; }

    void test_v2() override { std::cout << "Test v2!\n"; }
};

int main() {
    Client client{};
    
    Entity_v1& as_v1 = client;
    as_v1.test();
    
    Entity_v2& as_v2 = client;
    as_v2.test();
}
