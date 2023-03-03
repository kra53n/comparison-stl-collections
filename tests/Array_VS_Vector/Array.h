#pragma once
#include<array>
const int N = 100000000;
const int N1 = 100000;
class Array
{
	private:
		int idArray;
		
		std::array<int, N1> arr;
	public:
		Array(int id);
		void Create(int id);
		void addRand();
		double sortArray();
		double reverseArray();
		void printArray();
		double searchArray(int i);
		void vst(int i);
		double sumArray();
};

