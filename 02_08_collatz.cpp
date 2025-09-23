#include <iostream>
#include <algorithm>
#include <vector>

using ValueT = unsigned long long int;

const ValueT N_INITITAL_NUMBERS = 100;

ValueT find_seq_len(ValueT current, std::vector<std::size_t>& seq_lens) {
    if (current < std::ssize(seq_lens) && seq_lens[current] != -1) {
        return seq_lens[current];
    }

    while (std::ssize(seq_lens) <= current) {
        seq_lens.push_back(-1);
    }

    if (current % 2 == 0) {
        seq_lens[current] = find_seq_len(current / 2, seq_lens);
    } else {
        seq_lens[current] = find_seq_len(3 * current + 2, seq_lens);
    }
    return seq_lens[current];
}

int main() {
    std::vector<std::size_t> seq_lens;
    seq_lens.reserve(N_INITITAL_NUMBERS);
    seq_lens.push_back(0);

    for (ValueT i = 1; i <= N_INITITAL_NUMBERS; ++i) {
        std::cout << find_seq_len(i, seq_lens) << '\n';
    }
}