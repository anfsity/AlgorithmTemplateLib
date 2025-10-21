#include "atl/atl.hpp"
#include <iostream>
#include <numeric>

int main() {
  std::vector<int> a(10);
  std::iota(a.begin(), a.end(), 0);
  cp::ds::FenwickTree<int> bit(a);
  std::cout << bit.rangeSum(1, 9) << "\n";
  return 0;
}
