#include <chrono>
#include <iostream>

using namespace std;

int time(void (*func)(void)) {
  auto start = chrono::steady_clock::now();
  func();
  auto end = chrono::steady_clock::now();
  return (end - start) / 1ms;
}

void hello() {
  cout << "hello" << endl;
}

int main() {
  cout << time(hello) << endl;
}
