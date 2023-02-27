#pragma once

#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

// First function calling begins to mark the time. Second calling return time
// from previous calling in ms.
int timeit() {
  using namespace std;
  static bool is_started = false;
  static chrono::steady_clock::time_point start;
  if (is_started) {
    auto end = chrono::steady_clock::now();
    is_started = false;
    return (end - start) / 1ms;
  } else {
    start = chrono::steady_clock::now();
	is_started = true;
  }
  return 0;
}

// Count average time operation exectution. If operation time execution less
// than 500 ms, the operation repeated. In total, five such iterations are 
// performed.
int average(int (*func)(int, int), int num, int seed) {
  std::vector<int> vec;
  for (int i = 0; i < 5; i++) {
    int common_time = 0;
    while (common_time < 500) {
      int tmp = func(num, seed);
      common_time += tmp;
      vec.push_back(tmp);
    }
  }
  std::sort(vec.begin(), vec.end());
  int _sum = 0;
  int count = 0;
  int size = vec.size();
  int slice = size / 10;
  slice = slice == 0 ? 1 : slice;
  for (int i = slice; i < size - slice; i++, count++) {
    _sum += vec[i];
  }
  return _sum / count;
}

void test(
  std::fstream& file,
  std::string collection,
  std::string operation,
  int (*func)(int, int)
) {
  int seed = 333;
  //                    1 mb
  int elems_num[3] = { 131'072, 131'072 * 10, 131'072 * 100 };
  for (auto num : elems_num) {
    file << "collection " << collection << std::endl;
    file << "operation " << operation << std::endl;
    file << "elems_num " << num << std::endl;
    file << "time " << average(func, num, seed) << std::endl;
    file << std::endl;
    seed++;
  }
}
