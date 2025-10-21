#pragma once

#include <numeric>
#include <vector>

namespace cp {

namespace graph {

template <typename T>
class Dsu {
private:
    std::vector<T> father, size;
    size_t find (size_t x);
public:
    Dsu(size_t n = 0) :
    father(n, 0), size(n, 1) { std::iota(father.begin(), father.end(), 0); }

    void unite(size_t x, size_t y);
    bool same(size_t x, size_t y);
    std::ptrdiff_t getSize(size_t pos);
};

} // namespace graph

} // namespace cp