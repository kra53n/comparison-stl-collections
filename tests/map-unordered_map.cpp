#include <map>
#include <unordered_map>

#include <chrono>
#include <fstream>
#include <iostream>

#include "test.hpp"

using namespace std;

namespace t_map {

  map<int, int> create(int num, int seed) {
    srand(seed);
    map<int, int> m;
    for (int i = 0; i < num; i++) {
      int tmp = rand() * rand();
      m[tmp] = tmp;
    }
    return m;
  }

  int forward_iteration(int num, int seed) {
    auto m = create(num, seed);
    auto start = chrono::steady_clock::now();
    for (auto i = m.begin(); i != m.end(); i++) {
      int tmp = (*i).second;
      int res_tmp = tmp * tmp;
    }
    auto end = chrono::steady_clock::now();
    return (end - start) / 1ms;
  }

}; // t_map

namespace t_umap {

  unordered_map<int, int> create(int num, int seed) {
    srand(seed);
    unordered_map<int, int> m;
    for (int i = 0; i < num; i++) {
      int tmp = rand() * rand();
      m[tmp] = tmp;
    }
    return m;
  }

  int forward_iteration(int num, int seed) {
    auto m = create(num, seed);
    auto start = chrono::steady_clock::now();
    for (auto i = m.begin(); i != m.end(); i++) {
      int tmp = (*i).second;
      int res_tmp = tmp * tmp;
    }
    auto end = chrono::steady_clock::now();
    return (end - start) / 1ms;
  }

}; // t_umap

int main() {
  std::fstream file("map-unordered_map.txt", fstream::out);
  test(file, "map", "forward_iteration", t_map::forward_iteration);
}
