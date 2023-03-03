#include <iostream>
#include <list>
#include <vector> 
#include <chrono>
using namespace std;

//наброски для изучения работы с контейнерами

void insertvctr(std::vector<int>& a,int N)
{
    auto begin = std::chrono::steady_clock::now();
	 for (int i = 0; i < N; i++)
    {
        a[i] = rand()% 100;
       //std::cout << a[i] << ",";
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";
    /*for (int i = 0; i < N; i++)
    {
               std::cout << a[i] << ",";
    }*/
}

void push_frontlist(std::list<int>& a, int N)
{
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i < N; i++)
    {
        a.push_front(rand() % 100);
       // a.pop_back();
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";

    /*for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }*/
}

void push_backlist(std::list<int>& a, int N)
{
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i < N; i++)
    {
        a.push_back(rand() % 100);
      //  a.pop_front();
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";

    /*for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }*/
}

void pop_frontlst(std::list<int>& a, int c)
{
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i < c; i++)
    {
        a.pop_front();
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";

    /*for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }*/
}

void pop_backlst(std::list<int>& a, int c)
{
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i < c; i++)
    {
        a.pop_back();
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";

    /*for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }*/
}

void vctr_pop_back(std::vector<int>& a, int c)
{
    auto begin = std::chrono::steady_clock::now();

    for (int i = 0; i < c; i++)
    {
        a.pop_back();       
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";
}

int main()
{
    srand(time(NULL));

    int N = 90000000;
    int c = 90000000;
	std::vector <int> vctr(N);
    std::list <int> lst(N);

   insertvctr(vctr, N);
   //push_frontlist(lst, N);
   // push_backlist(lst, N);
   // cout  << "\n ";
   //pop_frontlst(lst, c);
   //pop_backlst(lst, c);
    vctr_pop_back(vctr, c);
	return 0;
}