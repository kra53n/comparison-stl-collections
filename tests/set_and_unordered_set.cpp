// C++ program for comparison set and unordered_set
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_set>
using namespace std;


int main()
{
    cout << "set char ";
    std::set<char> a;
    a.insert('G');
    a.insert('F');
    a.insert('G');
    
    for (auto& str : a) {
        std::cout << str << ' ';
    }

    std::cout << '\n';

    cout << "set int ";
    set<int, greater<int> > s1;
    s1.insert(10);
    s1.insert(5);
    s1.insert(12);
    s1.insert(4);

    for (auto i : s1) {
        cout << i << ' ';
    }

    std::cout << '\n';

    unordered_set<int> numbers{ 1, 100, 10, 70, 100 };

    cout << "unordered_set int ";
    for (auto& num : numbers) {
        cout << num << ", ";
    }

    return 0;
}