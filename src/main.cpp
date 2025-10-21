#include "atl/atl.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  cp::graph::Dsu<int> dsu(n);

  while(q --) {
    int t;
    std::cin >> t;
    int x, y;
    std::cin >> x >> y;
    x --, y --;
    if (t == 1) {
      dsu.unite(x, y);  
    } else {
      std::cout << (dsu.same(x, y) ? "Y" : "N") << "\n";
    }
  }
  return 0;
}
