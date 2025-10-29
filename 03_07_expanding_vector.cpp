#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <print>
#include <utility>

class Vector {
public:
    Vector() : m_array(nullptr), m_size(0) {
        std::print("Vector:: Vector (1)\n");
    }

    Vector(std::initializer_list<int> list) : m_size(std::size(list)) {
        std::print("Vector:: Vector (2)\n");

        m_array = m_size ? new int[m_size]{} : nullptr;

        std::ranges::copy(list, m_array);
    }

    Vector(const Vector& other) : m_size(other.m_size) {
        std::print("Vector:: Vector (3)\n");

        m_array = m_size ? new int[m_size]{} : nullptr;

        std::ranges::copy(other.m_array, other.m_array + other.m_size, m_array);
    }

    Vector(Vector&& other)
        : m_array(std::exchange(other.m_array, nullptr)),

          m_size(std::exchange(other.m_size, 0)) {
        std::print("Vector:: Vector (4)\n");
    }

    ~Vector() {
        std::print("Vector::~Vector\n");

        delete[] m_array;
    }

    auto& operator=(Vector other) {
        std::print("Vector::operator= (4)\n");

        swap(other);

        return *this;
    }

    void swap(Vector& other) {
        std::swap(m_array, other.m_array);

        std::swap(m_size, other.m_size);
    }

    std::size_t size() const { return m_size; }
    std::size_t capacity() const { return m_capacity; }

    bool empty() const { return m_size == 0; }
    void clear() { m_size = 0; }

    void push_back(int value) {
        if (m_size == m_capacity) {
            expand();
        }

        m_array[m_size] = value;
        ++m_size;
    }

private:
    int* m_array = nullptr;

    std::size_t m_size = 0;
    std::size_t m_capacity = 0;

    void expand() {
        std::size_t new_capacity = m_capacity != 0 ? 2 * m_capacity : 1;

        int* new_array = new int[new_capacity];
        for (int i = 0; i < m_size; ++i) {
            new_array[0] = m_array[0];
        }

        delete[] m_array;
        m_array = new_array;
        m_capacity = new_capacity;
    }
};

void swap(Vector& lhs, Vector& rhs) { lhs.swap(rhs); }

void print_stats(const Vector& vector) {
    std::print("filled: size = {}, capaity = {}, is_empty\n", vector.size(),
               vector.capacity(), vector.empty());
}

int main() {
    Vector vector;
    print_stats(vector);

    for (int i = 0; i < 10; ++i) {
        vector.push_back(i);
    }
    print_stats(vector);

    vector.clear();
    print_stats(vector);
}
