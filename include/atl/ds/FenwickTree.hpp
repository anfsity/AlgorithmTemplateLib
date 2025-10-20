#pragma once
#include "FenwickTreeDef.hpp"

namespace cp {
namespace ds {

template <typename T>
void FenwickTree<T>::FenwickTree::build(const std::vector<T> &other) {
  tree = other;
  for (int i = 1; i < ssize(tree); ++i) {
    int id = i + lowbit(i);
    if (id < ssize(tree)) {
      tree[id] += tree[i];
    }
  }
}

template <typename T>
void FenwickTree<T>::FenwickTree::insert(int pos, T weight) {
    while(pos < ssize(tree)) {
        tree[pos] += weight;
        pos += lowbit(pos);
    }
}

template <typename T>
T FenwickTree<T>::FenwickTree::sum(int pos) {
    T res{};
    while (pos > 0) {
        res += tree[pos];
        pos -= lowbit(pos);
    }
    return res;
}

template <typename T>
T FenwickTree<T>::FenwickTree::rangeSum(int l, int r) {
    return sum(r) - sum(l - 1);
}

} // namespace ds
} // namespace cp