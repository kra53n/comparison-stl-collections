#pragma once
#include<vector>
class Vectors{
	private:
		int idVector;
		std::vector<int> vect;
	public:
		Vectors(int id);
		void Create(int id);
		void addRand(int n);
		double sortVector();
		double reverseVector();
		void printVector();
		double searchArray(int i);
		void vst(int i);
		double sumVector();
};

