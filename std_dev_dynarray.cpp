#include <array>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
#include <utility>

int main() {
  const int ARRAY_LEN = 5;
  double* array = new double[ARRAY_LEN]{1, 2, 3, 4, 5};

  double mean = 0;
  for (int i = 0; i < ARRAY_LEN; ++i) {
    mean += array[i];
  }
  mean /= ARRAY_LEN;

  double std_dev = 0;
  for (int i = 0; i < ARRAY_LEN; ++i) {
    std_dev += (array[i] - mean) * (array[i] - mean);
  }
  std_dev = std::sqrt(std_dev / ARRAY_LEN);

  std::cout << std_dev;
}
