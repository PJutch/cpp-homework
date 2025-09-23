#include <array>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
#include <utility>

int main() {
  double array[5]{1, 2, 3, 4, 5};

  double mean = 0;
  for (int i = 0; i < std::ssize(array); ++i) {
    mean += array[i];
  }
  mean /= std::ssize(array);

  double std_dev = 0;
  for (int i = 0; i < std::ssize(array); ++i) {
    std_dev += (array[i] - mean) * (array[i] - mean);
  }
  std_dev = std::sqrt(std_dev / std::ssize(array));

  std::cout << std_dev;
}
