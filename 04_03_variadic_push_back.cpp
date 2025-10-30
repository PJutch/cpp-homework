#include <vector>
#include <cassert>

template <typename Container, typename... Args>
void push_back_all(Container& container, Args... args) {
    (container.push_back(args), ...);
}

int main() {
    std::vector<int> container;

    push_back_all(container, 1, 2, 3);
    assert(container == (std::vector{1, 2, 3}));
    
    push_back_all(container);
    assert(container == (std::vector{1, 2, 3}));
}
