#pragma once
#include <vector>

namespace cp {

namespace ds {

template <typename T> class FenwickTree {
private:
  std::vector<T> tree;
  int lowbit(int x) { return x & -x; };

public:
  FenwickTree(const std::vector<T> &other) { build(other); }
  void build (const std::vector<T> &other);
  void insert (int pos, T val);
  T sum (int pos);
  T rangeSum (int l, int r);
};

} // namespace ds

} // namespace cp
