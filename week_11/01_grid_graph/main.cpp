#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "grid_graph.hpp"

TEST(GridGraph, 2by2CycleBoolean) {
  const int rows = 2;
  const int cols = 2;
  GridGraph G {rows, cols};
  G.addEdge({0, 0}, {0, 1});
  G.addEdge({0, 1}, {1, 1});
  G.addEdge({1, 1}, {1, 0});
  G.addEdge({1, 0}, {0, 0});
  DirectedCycle cycleFinder {};
  EXPECT_TRUE(cycleFinder.containsCycle(G));
}

TEST(GridGraph, 2by2NoCycleBoolean) {
  const int rows = 2;
  const int cols = 2;
  GridGraph G {rows, cols};
  G.addEdge({0, 0}, {0, 1});
  G.addEdge({1, 1}, {0, 1});
  G.addEdge({1, 1}, {1, 0});
  G.addEdge({1, 0}, {0, 0});
  DirectedCycle cycleFinder {};
  EXPECT_FALSE(cycleFinder.containsCycle(G));
}

TEST(GridGraph, 2by2DontForgetToOffStack) {
  const int rows = 2;
  const int cols = 2;
  GridGraph G {rows, cols};
  G.addEdge({0, 0}, {0, 1});
  G.addEdge({0, 0}, {1, 0});
  G.addEdge({1, 0}, {1, 1});
  G.addEdge({0, 1}, {1, 1});
  DirectedCycle cycleFinder {};
  EXPECT_FALSE(cycleFinder.containsCycle(G));
}

TEST(GridGraph, 3by2DontForgetToOffStack) {
  const int rows = 3;
  const int cols = 2;
  GridGraph G {rows, cols};
  G.addEdge({0, 0}, {0, 1});
  G.addEdge({0, 0}, {1, 0});
  G.addEdge({1, 0}, {1, 1});
  G.addEdge({1, 1}, {0, 1});
  G.addEdge({1, 1}, {2, 1});
  G.addEdge({1, 0}, {2, 0});
  G.addEdge({2, 1}, {2, 0});
  DirectedCycle cycleFinder {};
  EXPECT_FALSE(cycleFinder.containsCycle(G));
}


TEST(GridGraph, 3by3CycleBoolean) {
  const int rows = 3;
  const int cols = 3;
  GridGraph G {rows, cols};
  G.addEdge({0, 0}, {0, 1});
  G.addEdge({0, 2}, {0, 1});
  G.addEdge({1, 0}, {0, 0});
  G.addEdge({0, 1}, {1, 1});
  G.addEdge({0, 2}, {1, 2});
  G.addEdge({1, 1}, {1, 2});
  G.addEdge({1, 0}, {1, 1});
  G.addEdge({2, 0}, {1, 0});
  G.addEdge({2, 1}, {2, 0});
  G.addEdge({1, 2}, {2, 2});
  G.addEdge({2, 2}, {2, 1});
  DirectedCycle cycleFinder {};
  EXPECT_TRUE(cycleFinder.containsCycle(G));
}

TEST(GridGraph, 3by3NoCycleBoolean) {
  const int rows = 3;
  const int cols = 3;
  GridGraph G {rows, cols};
  G.addEdge({0, 0}, {0, 1});
  G.addEdge({0, 2}, {0, 1});
  G.addEdge({1, 0}, {0, 0});
  G.addEdge({0, 1}, {1, 1});
  G.addEdge({0, 2}, {1, 2});
  G.addEdge({1, 2}, {1, 1});
  G.addEdge({1, 0}, {1, 1});
  G.addEdge({2, 0}, {1, 0});
  G.addEdge({2, 1}, {2, 0});
  G.addEdge({1, 2}, {2, 2});
  G.addEdge({2, 2}, {2, 1});
  DirectedCycle cycleFinder {};
  EXPECT_FALSE(cycleFinder.containsCycle(G));
}

TEST(GridGraph, 2by4CycleBoolean) {
  const int rows = 3;
  const int cols = 3;
  GridGraph G {rows, cols};
  G.addEdge({0, 0}, {0, 1});
  G.addEdge({0, 2}, {0, 1});
  G.addEdge({1, 0}, {0, 0});
  G.addEdge({0, 1}, {1, 1});
  G.addEdge({0, 2}, {1, 2});
  G.addEdge({1, 2}, {1, 1});
  G.addEdge({1, 0}, {1, 1});
  G.addEdge({2, 0}, {1, 0});
  G.addEdge({2, 1}, {2, 0});
  G.addEdge({1, 2}, {2, 2});
  G.addEdge({2, 2}, {2, 1});
  DirectedCycle cycleFinder {};
  EXPECT_FALSE(cycleFinder.containsCycle(G));
}

// random grid
GridGraph makeRandomGrid(int N, unsigned seed) {
  GridGraph G {N, N};
  int numberOfEdges = 2 * N * N;
  std::mt19937 mt {seed};
  std::bernoulli_distribution dist {};
  std::vector<bool> choices(numberOfEdges);
  std::generate(choices.begin(), choices.end(),
    [&mt, &dist](){return dist(mt);});
  int counter = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = 0; j < N - 1; ++j) {
      choices.at(counter++) ? G.addEdge({i, j}, {i, j + 1}) :
                            G.addEdge({i, j + 1}, {i, j});
      choices.at(counter++) ? G.addEdge({i, j}, {i + 1, j}) :
                            G.addEdge({i + 1, j}, {i, j});
    }
  }
  for (int i = 0; i < N - 1; ++i) {
    choices.at(counter++) ? G.addEdge({i, N - 1}, {i + 1, N - 1}) :
                          G.addEdge({i + 1, N - 1}, {i, N - 1});
    choices.at(counter++) ? G.addEdge({N - 1, i}, {N - 1, i + 1}) :
                          G.addEdge({N - 1, i + 1}, {N - 1, i});
  }
  return G;
}

TEST(GridGraph, random5by5Grid) {
  const int N = 5;
  GridGraph G = makeRandomGrid(N, 888'888);
  DirectedCycle cycleFinder {};
  EXPECT_TRUE(cycleFinder.containsCycle(G));
}

TEST(GridGraph, random10by10Grid) {
  const int N = 10;
  GridGraph G = makeRandomGrid(N, 23'893'289);
  DirectedCycle cycleFinder {};
  EXPECT_TRUE(cycleFinder.containsCycle(G));
}

// test that vertices on cycle actually form cycle
void checkCycle(const std::vector<std::pair<int, int> >& cycle,
                                  const GridGraph& G) {
  ASSERT_GE(cycle.size(), 2u);
  for (std::size_t i = 1; i < cycle.size(); ++i) {
    EXPECT_TRUE(G.isEdge(cycle.at(i - 1), cycle.at(i)));
  }
  EXPECT_TRUE(G.isEdge(cycle.back(), cycle.front()));
}

TEST(GridGraph, 2by2Cycle) {
  const int rows = 2;
  const int cols = 2;
  GridGraph G {rows, cols};
  G.addEdge({0, 0}, {0, 1});
  G.addEdge({0, 1}, {1, 1});
  G.addEdge({1, 1}, {1, 0});
  G.addEdge({1, 0}, {0, 0});
  DirectedCycle cycleFinder {};
  EXPECT_TRUE(cycleFinder.containsCycle(G));
  checkCycle(cycleFinder.getCycle(), G);
}

TEST(GridGraph, 3by3Cycle) {
  const int rows = 3;
  const int cols = 3;
  GridGraph G {rows, cols};
  G.addEdge({0, 0}, {0, 1});
  G.addEdge({0, 2}, {0, 1});
  G.addEdge({1, 0}, {0, 0});
  G.addEdge({0, 1}, {1, 1});
  G.addEdge({0, 2}, {1, 2});
  G.addEdge({1, 1}, {1, 2});
  G.addEdge({1, 0}, {1, 1});
  G.addEdge({2, 0}, {1, 0});
  G.addEdge({2, 1}, {2, 0});
  G.addEdge({1, 2}, {2, 2});
  G.addEdge({2, 2}, {2, 1});
  DirectedCycle cycleFinder {};
  EXPECT_TRUE(cycleFinder.containsCycle(G));
  checkCycle(cycleFinder.getCycle(), G);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
