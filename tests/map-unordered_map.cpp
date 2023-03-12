#include <map>
#include <unordered_map>

#include <chrono>
#include <fstream>
#include <iostream>

#include "test.hpp"

using namespace std;

#define imap map<int, int>
#define umap unordered_map<int, int>

#define rand2 rand() * rand()

template<typename T>
T create(int num, int seed) {
  srand(seed);
  T type;
  while (type.size() < num) {
    int tmp = rand2;
    type[tmp] = tmp;
  }
  return type;
}

template<typename T>
T create_by_strings(int num, int seed) {
  srand(seed);
  T type;
  while (type.size() < num) {
    int tmp = rand2;
    type[tmp] = tmp;
  }
  return type;
}

template<typename T>
int forward_iteration(int num, int seed) {
  T m = create<T>(num, seed);
  timeit();
  for (auto i = m.begin(); i != m.end(); i++) {
    int tmp = i->second;
    int res_tmp = tmp * tmp;
  }
  return timeit();
}

template<typename T>
int const_forward_iteration(int num, int seed) {
  T m = create<T>(num, seed);
  timeit();
  for (auto i = m.cbegin(); i != m.cend(); i++) {
    int tmp = (*i).second;
    int res_tmp = tmp * tmp;
  }
  return timeit();
}

template<typename T>
int merge(int num, int seed) {
  T m1 = create<T>(num, seed);
  T m2 = create<T>(num, seed+1);
  timeit();
  m1.merge(m2);
  return timeit();
}

template<typename T>
int insert(int num, int seed) {
  T m1 = create<T>(num, seed);
  T m2 = create<T>(num, seed);
  auto it = m2.begin();
  for (int i = 0; i < 50'000; i++, it++);
  timeit();
  m1.insert(it, m2.end());
  return timeit();
}

template<typename T>
int find(int num, int seed) {
  T m = create<T>(num, seed);
  vector<int> finds;
  for (auto it = m.begin(); finds.size() < 30'000;) {
    finds.push_back(it->first);
    int tmp = rand() % 3 + 1;
	for (int j = 0; j < tmp; j++) {
	  it++;
	}
  }
  vector<int> unfinds;
  do {
    int tmp = rand2;
	if (m[tmp]) {
	  continue;
	}
	unfinds.push_back(tmp);
  } while(unfinds.size() < 30'000);
  timeit();
  for (auto k : finds) {
	int v = m[k] ? m[k] : 2;
	int tmp = v * v;
  }
  return timeit();
}

template<typename T>
int erase(int num, int seed) {
  T m = create<T>(num, seed);
  auto it = m.begin();
  for (int i = 0; i < 50'000; i++, it++);
  timeit();
  m.erase(it, m.end());
  return timeit();
}

template<typename T>
int clear(int num, int seed) {
  T m = create<T>(num, seed);
  timeit();
  m.clear();
  return timeit();
}

template<typename T>
int copy(int num, int seed) {
  T m1 = create<T>(num, seed);
  timeit();
  T m2 = m1;
  return timeit();
}

int main() {
  fstream file("map-unordered_map.txt", fstream::out);
  test(file, "map",  "forward_iteration", forward_iteration<imap>);
  test(file, "umap", "forward_iteration", forward_iteration<umap>);
  test(file, "map",  "const_forward_iteration", const_forward_iteration<imap>);
  test(file, "umap", "const_forward_iteration", const_forward_iteration<umap>);
  test(file, "map",  "merge", merge<imap>);
  test(file, "umap", "merge", merge<umap>);
  test(file, "map",  "insert", insert<imap>);
  test(file, "umap", "insert", insert<umap>);
  test(file, "map",  "find", find<imap>);
  test(file, "umap", "find", find<umap>);
  test(file, "map",  "erase", erase<imap>);
  test(file, "umap", "erase", erase<umap>);
  test(file, "map",  "clear", clear<imap>);
  test(file, "umap", "clear", clear<umap>);
  test(file, "map",  "copy", copy<imap>);
  test(file, "umap", "copy", copy<umap>);
}
