#include "Array.h"
#include <iostream>
#include <algorithm>
#include<array>
#include <chrono>

Array::Array(int id)
{
	idArray = id;
}

void Array::Create(int id)
{
	idArray = id;
}

void Array::addRand()
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < arr.size(); i++) {
        long random_num = rand() % 1000;
        arr[i] = random_num;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken to ADD Rand the array: " << diff.count() << "s" << std::endl;
}

double Array::sortArray()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken to sort the array: " << diff.count() << "s" << std::endl;
    return static_cast<double>(diff.count());
}

double Array::reverseArray()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::reverse(arr.begin(), arr.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken to reverse the array: " << diff.count() << "s" << std::endl;
    return static_cast<double>(diff.count());
}

void Array::printArray()
{
    int i = 0;
    while (i++ < arr.size()-1)
    {
        std::cout << arr[i] << "\n";
    }
}

double Array::searchArray(int i)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto it = std::find(arr.begin(), arr.end(), 1925473);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    if (it != arr.end())
    {
        std::cout << "Value found: " << *it << std::endl;
    }
    else
    {
        std::cout << "Value not found" << std::endl;
    }
    std::cout << "Time taken to search the array: " << diff.count() << "s" << std::endl;
    return static_cast<double>(diff.count());
}

void Array::vst(int i)
{
    arr[i] = 1925473;
}

double Array::sumArray()
{
    int i = 0;
    int sum = 0;
    auto start = std::chrono::high_resolution_clock::now();
    while (i++ < arr.size()-1)
    {
        sum += arr[i];
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken to sum the array: " << diff.count() << "s " << "Sum = " << sum << std::endl;
    return static_cast<double>(diff.count());
}

