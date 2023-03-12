#include <iostream>
#include <list>
#include <vector> 
#include <chrono>
#include <iterator>
using namespace std;

//наброски для изучения работы с контейнерами

void insertvctr(std::vector<int>& a,int N)
{
    auto begin = std::chrono::steady_clock::now();
	 for (int i = 0; i < N; i++)
    {
         int num = rand() % 100;
         a.insert(a.begin(),num);
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
        a.insert(it, rand() % 100);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
   std::cout << "The time: " << elapsed_ms.count() << " ms\n";
     /* for (list<int>::iterator i = a.begin(); i != a.end(); i++)
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

    for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }
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

void push_random_vctr(std::vector<int>& a,int c,int N)
{
    auto begin = std::chrono::steady_clock::now();
    

    for (int i = 0; i < c; i++)
    {
        int num = rand() % 100;
        a.insert(a.begin() + rand() % 10, num); 
        N+=1;
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";
    /*for (int i = 0; i < N; i++)
    {
               std::cout << a[i] << ",";
    }*/
}

void push_random_list(std::list<int>& a, int c,int N)
{
    auto begin = std::chrono::steady_clock::now();
    list <int>::iterator it;
    
    for (int i = 0; i < c; i++)
    {
        std::list < int > ::iterator newIterator = a.begin();
    
        std::advance(newIterator, rand() % 100);
        a.insert(newIterator, rand()%100);
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";

   /* for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }*/
}

int main()
{
    srand(time(NULL));

    int N = 90000;
    int c = 90000;
	std::vector <int> vctr(N);
    std::list <int> lst(N);

   //insertvctr(vctr, N);
   //cout << "\n ";
   //push_random_vctr(vctr, c,N);
   //push_frontlist(lst, N);
   // push_backlist(lst, N);
    insert_lst(lst, N);
    cout  << "\n ";
    push_random_list(lst, c, N);
   //pop_frontlst(lst, c);
   //pop_backlst(lst, c);
    //vctr_pop_back(vctr, c);
	return 0;
}