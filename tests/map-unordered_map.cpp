#include <map>
#include <unordered_map>

#include <chrono>
#include <fstream>
#include <iostream>

#include "test.hpp"

using namespace std;

#define imap map<int, int>
#define umap unordered_map<int, int>

template<typename T>
T create(int num, int seed) {
  srand(seed);
  T m;
  for (int i = 0; i < num; i++) {
    int tmp = rand() * rand();
    m[tmp] = tmp;
  }
  return m;
}

template<typename T>
int forward_iteration(int num, int seed) {
  T m = create<T>(num, seed);
  auto start = chrono::steady_clock::now();
  for (auto i = m.begin(); i != m.end(); i++) {
    int tmp = (*i).second;
    int res_tmp = tmp * tmp;
  }
  auto end = chrono::steady_clock::now();
  return (end - start) / 1ms;
}


int main() {
  std::fstream file("map-unordered_map.txt", fstream::out);
  test(file, "map",  "forward_iteration", forward_iteration<imap>);
  test(file, "umap", "forward_iteration", forward_iteration<umap>);
}
