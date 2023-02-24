#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

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
  for (int num = 400'000, seed = 333; num <= 52'428'800; num += 300'000, seed++) {
	file << "collection " << collection << std::endl;
	file << "operation " << operation << std::endl;
	file << "elems_num " << num << std::endl;
	file << "time " << average(func, num, seed) << std::endl;
	file << std::endl;
  }
}
