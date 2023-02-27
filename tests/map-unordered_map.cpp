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
T* create(int num, int seed) {
  srand(seed);
  T* type = new T;
  while (type->size() < num) {
    int tmp = rand2;
    (*type)[tmp] = tmp;
  }
  return type;
}

template<typename T>
int forward_iteration(int num, int seed) {
  T* m = create<T>(num, seed);
  timeit();
  for (auto i = m->begin(); i != m->end(); i++) {
    int tmp = (*i).second;
    int res_tmp = tmp * tmp;
  }
  return timeit();
}

template<typename T>
int const_forward_iteration(int num, int seed) {
  T* m = create<T>(num, seed);
  auto start = chrono::steady_clock::now();
  for (auto i = m->cbegin(); i != m->cend(); i++) {
    int tmp = (*i).second;
    int res_tmp = tmp * tmp;
  }
  auto end = chrono::steady_clock::now();
  return (end - start) / 1ms;
}

template<typename T>
int merge(int num, int seed) {
  T* m1 = create<T>(num, seed);
  T* m2 = create<T>(num, seed+1);
  auto start = chrono::steady_clock::now();
  m1->merge(*m2);
  auto end = chrono::steady_clock::now();
  return (end - start) / 1ms;
}

template<typename T>
int erase(int num, int seed) {
  T* m = create<T>(num, seed);
  auto it = m->begin();
  for (int i = 0; i < 50'000; i++, it++);
  auto start = chrono::steady_clock::now();
  m->erase(it, m->end());
  auto end = chrono::steady_clock::now();
  return (end - start) / 1ms;
}

template<typename T>
int clear(int num, int seed) {
  T* m = create<T>(num, seed);
  auto start = chrono::steady_clock::now();
  m->clear();
  auto end = chrono::steady_clock::now();
  return (end - start) / 1ms;
}

template<typename T>
int copy(int num, int seed) {
  T* m1 = create<T>(num, seed);
  auto start = chrono::steady_clock::now();
  T m2 = *m1;
  auto end = chrono::steady_clock::now();
  return (end - start) / 1ms;
}

int main() {
  std::fstream file("map-unordered_map.txt", fstream::out);
  test(file, "map",  "forward_iteration", forward_iteration<imap>);
  test(file, "umap", "forward_iteration", forward_iteration<umap>);
  test(file, "map",  "const_forward_iteration", const_forward_iteration<imap>);
  test(file, "umap", "const_forward_iteration", const_forward_iteration<umap>);
  test(file, "map",  "merge", merge<imap>);
  test(file, "umap", "merge", merge<umap>);
  test(file, "map",  "erase", erase<imap>);
  test(file, "umap", "erase", erase<umap>);
  test(file, "map",  "clear", clear<imap>);
  test(file, "umap", "clear", clear<umap>);
  test(file, "map",  "copy", copy<imap>);
  test(file, "umap", "copy", copy<umap>);
}
