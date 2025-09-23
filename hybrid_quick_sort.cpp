#include <algorithm>
#include <cassert>
#include <cstddef>
#include <numeric>
#include <utility>
#include <vector>

void order(std::vector<int>& vector, std::size_t left, std::size_t right) {
    for (auto i = left + 1; i < right; ++i) {
        for (auto j = i; j > left; --j) {
            if (vector[j - 1] > vector[j]) {
                std::swap(vector[j], vector[j - 1]);
            }
        }
    }
}

std::size_t partition(std::vector<int>& vector, std::size_t left,
                      std::size_t right) {
    if (left >= right) {
        return 0;
    }

    int pivot = vector[left];

    std::size_t i = left;
    std::size_t j = right;
    while (i < j) {
        if (vector[i] <= pivot) {
            ++i;
        } else if (vector[j] > pivot) {
            --j;
        } else {
            std::swap(vector[i], vector[j]);
        }
    }

    if (i == right) {
        std::swap(vector[left], vector[right - 1]);
        return right - 1;
    } else {
        return i;
    }
}

void split(std::vector<int>& vector, std::size_t left, std::size_t right) {
    if (right - left > 64) {
        std::size_t split_index = partition(vector, left, right);
        split(vector, left, split_index);
        split(vector, split_index, right);
    } else {
        order(vector, left, right);
    }
}

void sort(std::vector<int>& vector) { split(vector, 0, std::size(vector)); }

int main() {
    auto size = 1'000uz;

    std::vector<int> vector(size, 0);

    for (auto i = 0uz; i < size; ++i) {
        vector[i] = size - i;
    }

    sort(vector);

    assert(std::ranges::is_sorted(vector));
}
