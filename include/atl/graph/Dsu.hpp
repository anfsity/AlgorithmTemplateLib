#pragma once
#include "DsuDef.hpp"

template <typename T> size_t cp::graph::Dsu<T>::Dsu::find(size_t x) {
  if (father[x] != x) {
    father[x] = find(father[x]);
  }
  return father[x];
}

template <typename T> void cp::graph::Dsu<T>::Dsu::unite(size_t x, size_t y) {
  x = find(x), y = find(y);
  if (x == y)
    return;
  if (size[x] > size[y]) {
    std::swap(x, y);
  }
  father[x] = y;
  size[y] = size[y] + size[x];
}

template <typename T> bool cp::graph::Dsu<T>::Dsu::same(size_t x, size_t y) {
  return find(x) == find(y);
}

template <typename T>
std::ptrdiff_t cp::graph::Dsu<T>::Dsu::getSize(size_t pos) {
  return size[find(pos)];
}