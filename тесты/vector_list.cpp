#include <iostream>
#include <algorithm>
#include <list>
#include <vector> 
#include <chrono>
using namespace std;


void insertvctr(std::vector<int>& a, int N)
{
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 100;
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

void insert_lst(std::list<int>& a, int N)
{
    auto begin = std::chrono::steady_clock::now();
    list<int>::iterator it = a.begin();
    for (int i = 0; i < N; i++)
    {
        a.insert(it,rand() % 100);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";
  /*  for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
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

void sort_vctr(std::vector<int>& a, int N)
{
    auto begin = std::chrono::steady_clock::now();
    std::sort(a.begin(), a.end());
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";
}

void sort_lst(std::list<int>& a, int N)
{
    auto begin = std::chrono::steady_clock::now();
    a.sort();
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";
   /* for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }*/
}

void vctr_push_back(std::vector<int>& a, int N)
{
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i < N; i++)
    {
        int num = rand() % 100;
        a.push_back(num);
    }
    
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";
    /*for (int i = 0; i < N; i++)
    {
       std::cout << a[i] << ",";
    }*/
}

int main()
{
    srand(time(NULL));
    
    int N = 9000000;
    int c = 90000;
    std::vector <int> vctr(N);
    std::list <int> lst(N);
   
    vctr_push_back(vctr, N);
    //insert_lst(lst, N);
    //insertvctr(vctr, N);
    //push_frontlist(lst, N);
    // push_backlist(lst, N);
    //cout  << "\n ";
    //pop_frontlst(lst, c);
    //pop_backlst(lst, c);
    //vctr_pop_back(vctr, c);
    // sort_vctr(vctr, N);
    //sort_lst(lst, N);
    return 0;
}
