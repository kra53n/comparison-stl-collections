#include <map>
#include <chrono>
#include <iostream>

using namespace std;

namespace t_map {

  map<int, int> create_map(int num, int seed) {
	srand(seed);
	map<int, int> m;
	for (int i = 0; i < num; i++) {
	  int tmp = rand();
	  m[tmp] = tmp;
	}
	return m;
  }

  int forward_iteration(int num, int seed) {
	auto m = create_map(num, seed);
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	return (end - start) / 1ms;
  }

}; // t_map

namespace t_umap {



}; // t_umap

int main() {
  cout << t_map::forward_iteration(10'000'000, 333) << endl;
}
