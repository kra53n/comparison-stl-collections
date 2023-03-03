#include "Vectors.h"
#include <iostream>
#include <algorithm>
#include<vector>
#include <chrono>

Vectors::Vectors(int id)
{
    idVector = id;
}

void Vectors::Create(int id)
{
	idVector = id;
}

void Vectors::addRand(int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        long random_num = rand() % 1000;
        vect.push_back(random_num);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken to ADD Rand the vector: " << diff.count() << "s" << std::endl;
}

double Vectors::sortVector()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(vect.begin(),vect.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken to sort the vector: " << diff.count() << "s" << std::endl;
    return static_cast<double>(diff.count());
}

double Vectors::reverseVector()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::reverse(vect.begin(), vect.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken to reverse the vector: " << diff.count() << "s" << std::endl;
    return static_cast<double>(diff.count());
}

void Vectors::printVector()
{
    int i = 0;
    while (i++ < vect.size()-1)
    {
        std::cout << vect[i] << "\n";
    }
}

double Vectors::searchArray(int i)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto it = std::find(vect.begin(), vect.end(), 1925473);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    if (it != vect.end())
    {
        std::cout << "Value found: " << *it << std::endl;
    }
    else
    {
        std::cout << "Value not found" << std::endl;
    }
    std::cout << "Time taken to search the vector: " << diff.count() << "s" << std::endl;
    return static_cast<double>(diff.count());
}

void Vectors::vst(int i)
{
    vect[i] = 1925473;
}

double Vectors::sumVector()
{
    int i = 0;
    int sum = 0;
    auto start = std::chrono::high_resolution_clock::now();
    while (i++ < vect.size()-1)
    {
        sum += vect[i];
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken to sum the array: " << diff.count() << "s " << "Sum = " << sum << std::endl;
    return static_cast<double>(diff.count());
}
