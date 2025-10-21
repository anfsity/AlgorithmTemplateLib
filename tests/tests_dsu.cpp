#include "atl/atl.hpp"
#include <gtest/gtest.h>

TEST (DsuTest, BasicInitialization) {
  constexpr int n = 100;
  cp::graph::Dsu<int> dsu(n);
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      EXPECT_FALSE(dsu.same(i, i - 1));
    }
    EXPECT_EQ(dsu.getSize(i), 1);
  }
}

TEST (DsuTest, UniteFunction) {
  constexpr int n = 10;
  cp::graph::Dsu<int> dsu(n);

  dsu.unite(1, 2);
  dsu.unite(2, 4);
  dsu.unite(3, 8);

  EXPECT_TRUE(dsu.same(1, 4));
  EXPECT_TRUE(dsu.same(3, 8));
  EXPECT_TRUE(dsu.same(2, 4));
  EXPECT_FALSE(dsu.same(4, 8));
  EXPECT_FALSE(dsu.same(3, 2));
}

TEST (DsuTest, getSizeFunction) {
  constexpr int n = 10;
  cp::graph::Dsu<int> dsu(n);
  for (int i = 0; i < n - 5; ++i) {
    dsu.unite(i, i + 1);
  }

  EXPECT_EQ(dsu.getSize(0), 6);
  EXPECT_EQ(dsu.getSize(1), 6);
  EXPECT_EQ(dsu.getSize(2), 6);
  EXPECT_EQ(dsu.getSize(3), 6);
  EXPECT_EQ(dsu.getSize(4), 6);
  EXPECT_TRUE(dsu.same(4, 5));
  EXPECT_EQ(dsu.getSize(6), 1);
  EXPECT_EQ(dsu.getSize(7), 1);
  EXPECT_EQ(dsu.getSize(8), 1);
}