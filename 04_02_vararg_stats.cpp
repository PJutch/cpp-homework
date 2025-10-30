#include <array>
#include <cassert>
#include <iostream>

std::array<double, 0> filter_doubles() { return {}; }

template <typename T1, typename... Ts>
auto filter_doubles(const T1&, const Ts&... xs);

template <typename... Ts>
auto filter_doubles(const double& x1, const Ts&... xs) {
    return std::apply(
        [x1](auto... rest_filtered) {
            return std::array{x1, rest_filtered...};
        },
        filter_doubles(xs...));
}

template <typename T1, typename... Ts>
auto filter_doubles(const T1&, const Ts&... xs) {
    return filter_doubles(xs...);
}

template <typename... Ts> double min(const Ts&... xs) {
    return std::apply([](auto... doubles) { return std::min({doubles...}); },
                      filter_doubles(xs...));
}

template <typename... Ts> double max(const Ts&... xs) {
    return std::apply([](auto... doubles) { return std::max({doubles...}); },
                      filter_doubles(xs...));
}

template <typename... Ts> double sum(const Ts&... xs) {
    return std::apply([](auto... doubles) { return (doubles + ...); },
                      filter_doubles(xs...));
}

template <typename... Ts> double mean(const Ts&... xs) {
    return std::apply(
        [](auto... doubles) { return (doubles + ...) / sizeof...(doubles); },
        filter_doubles(xs...));
}

int main() {
    const double EPSILON = 1e-10;
    
    assert(std::abs(min(1.0, 2.0, "whatever", 4, 5.0) - 1.0) < EPSILON);
    assert(std::abs(max(1.0, 2.0, "whatever", 4, 5.0) - 5.0) < EPSILON);
    assert(std::abs(sum(1.0, 2.0, "whatever", 4, 5.0) - 8.0) < EPSILON);
    assert(std::abs(mean(1.0, 2.0, "whatever", 4, 5.0) - 2.6666666667) < EPSILON);
}
