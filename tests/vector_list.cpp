#include <iostream>
#include <list>
#include <vector> 
using namespace std;

//наброски для изучения работы с контейнерами

void insertvctr(std::vector<int>& a,int N)
{
	 for (int i = 0; i < N; i++)
    {
        a[i] = rand()% 100;
        std::cout << a[i] << ",";
    }
}

void push_frontlist(std::list<int>& a, int N)
{
    for (int i = 0; i < N; i++)
    {
        a.push_front(rand() % 100);
       // a.pop_back();
    }
    for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }
}

void push_backlist(std::list<int>& a, int N)
{
    for (int i = 0; i < N; i++)
    {
        a.push_back(rand() % 100);
      //  a.pop_front();
    }
    for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }
}

void pop_frontlst(std::list<int>& a, int c)
{
    for (int i = 0; i < c; i++)
    {
        a.pop_front();
    }
    for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }
}


void pop_backlst(std::list<int>& a, int c)
{
    for (int i = 0; i < c; i++)
    {
        a.pop_back();
    }
    for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }
}

int main()
{
    srand(time(NULL));

    int N = 25;

	std::vector <int> vctr(N);
    std::list <int> lst(N);

   // insertvctr(vctr, N);
    push_frontlist(lst, N);
    //push_backlist(lst, N);
    //pop_frontlst(lst, 5);
    pop_backlst(lst, 5);
	return 0;
}