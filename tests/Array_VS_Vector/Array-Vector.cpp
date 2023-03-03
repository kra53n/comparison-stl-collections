#include <array>
#include <thread>
#include "Vectors.h"
#include <iostream>
#include <algorithm>
#include "Array.h"

double  RunLearningVectorSort(int numbers) 
{
    int i = 0;
    int n = 10;
    double sumTime(0);
    while (i++ < n)
    {
        Vectors vctr = Vectors(1);
        vctr.addRand(numbers);
        double time = vctr.sortVector();
        sumTime += time;
        std::cout << time << "\n";
    }
    std::cout << "Final time: " << (sumTime / n) << '\n';
    return (sumTime / n);
}
double RunLearningVectorRevers(int numbers)
{
    int i = 0;
    int n = 10;
    double sumTime(0);
    while (i++ < n)
    {
        Vectors vctr = Vectors(1);
        vctr.addRand(numbers);
        double time = vctr.reverseVector();
        sumTime += time;
        std::cout << time << "\n";
    }
    std::cout << "Final time: " << (sumTime / n) << '\n';
    return (sumTime / n);
}
double RunLearningVectorSearch(int numbers, int s)
{
    int i = 0;
    int n = 10;
    double sumTime(0);
    while (i++ < n)
    {
        Vectors vctr = Vectors(1);
        vctr.addRand(numbers);
        vctr.vst(s);
        double time = vctr.searchArray(s);
        sumTime += time;
        std::cout << time << "\n";
    }
    std::cout << "Final time: " << (sumTime / n) << '\n';
    return (sumTime / n);
}
double RunLearningVectorSum(int numbers)
{
    int i = 0;
    int n = 10;
    double sumTime(0);
    while (i++ < n)
    {
        Vectors vctr = Vectors(1);
        vctr.addRand(numbers);
        double time = vctr.sumVector();
        sumTime += time;
        std::cout << time << "\n";
    }
    std::cout << "Final time: " << (sumTime / n) << '\n';
    return (sumTime / n);
}

double RunLearningArraySort()
{
    int i = 0;
    int n = 10;
    double sumTime(0);
    while (i++ < n)
    {
        Array * arr = new Array(1);
        arr->addRand();
        double time = arr->sortArray();
        sumTime += time;
        std::cout << time << "\n";
        delete arr;
    }
    std::cout << "Final time: " << (sumTime / n) << '\n';
    return (sumTime / n);
}
double RunLearningArrayRevers()
{
    int i = 0;
    int n = 10;
    double sumTime(0);
    while (i++ < n)
    {
        Array * arr =  new Array(1);
        arr->addRand();
        double time = arr->reverseArray();
        sumTime += time;
        std::cout << time << "\n";
        delete arr;
    }
    std::cout << "Final time: " << (sumTime / n) << '\n';
    return (sumTime / n);
}
double RunLearningArraySearch(int s)
{
    int i = 0;
    int n = 10;
    double sumTime(0);
    while (i++ < n)
    {
        Array* arr = new Array(1);
        arr->addRand();
        arr->vst(s);
        double time = arr->searchArray(s);
        sumTime += time;
        std::cout << time << "\n";
        delete arr;
    }
    std::cout << "Final time: " << (sumTime / n) << '\n';
    return (sumTime / n);
}
double RunLearningArraySum()
{
    int i = 0;
    int n = 10;
    double sumTime(0);
    while (i++ < n)
    {
        Array* arr = new Array(1);
        arr->addRand();
        double time = arr->sumArray();
        sumTime += time;
        std::cout << time << "\n";
        delete arr;
    }
    std::cout << "Final time: " << (sumTime / n) << '\n';
    return (sumTime / n);
}

int main()
{
    int numbers = 100000000;
    int numbers1 = 100000;
    double SumA = RunLearningArraySum();
    double SumV = RunLearningVectorSum(numbers1);
    /*
    double SA = RunLearningArraySearch(5000000);
    double SV = RunLearningVectorSearch(numbers, 5000000);
    double VS = RunLearningVectorSort(numbers);
    double VR = RunLearningVectorRevers(numbers);
    double AS = RunLearningArraySort();
    double AR = RunLearningArrayRevers();
    std::cout << "Vector search " << SV << "  VS  " << " Array search " << SA << '\n';
    std::cout << "Vector sort " << VS << "  VS  " << " Array sort " << AS << '\n';
    std::cout << "Vector revers " << VR << "  VS  " << " Array revers " << AR << '\n';
    */
    std::cout << "Vector sum " << SumV << "  VS  " << " Array sum " << SumA << '\n';
}























/*

// Function to sort a given vector
double sortVector(std::vector<long>& vec, int i) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(), vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << i << "Time taken to sort the vector: " << diff.count() << "s" << std::endl;
    return diff.count();
}

// Function to sort a given array
double sortArray(std::array<long, 10000000>& arr, int i) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << i <<  "Time taken to sort the array: " << diff.count() << "s" << std::endl;
    return diff.count();
}

bool valueÑomparison(std::vector<long>& vec, std::array<long, 10000000>& arr, int i) {
    auto start = std::chrono::high_resolution_clock::now();
    bool is_equal = std::equal(vec.begin(), vec.end(), arr.begin(), arr.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << i <<  "Time Comprarison: " << diff.count() << is_equal << std::endl;
    return 0;
}

bool valueÑomparisonVvV(std::vector<long>& vec1, std::vector<long>& vec2, int i) {
    auto start = std::chrono::high_resolution_clock::now();
    bool is_equal = std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << i << "Time Comprarison VvV: " << diff.count() << " " << is_equal << std::endl;
    return 0;
}

bool valueÑomparisonAvA(std::array<long, 10000000>& arr1, std::array<long, 10000000>& arr2, int i) {
    auto start = std::chrono::high_resolution_clock::now();
    bool is_equal = std::equal(arr1.begin(), arr1.end(), arr2.begin(), arr2.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << i << "Time ComprarisonAvA: " << diff.count() << " " << is_equal << std::endl;
    return 0;
}
void runTime() {
    double sumV = 0;
    double sumA = 0;
    for (int i = 0; i < 50; i++)
    {
        std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
        std::vector<long> vec;
        std::array<long, 10000000> arr;
        // Generate 100,000 random values and store them in the vector and array
        for (int i = 0; i < 10000000; i++) {
            long random_num = rand() % 10000000;
            vec.push_back(random_num);
            arr[i] = random_num;
        }
        valueÑomparison(vec, arr, i);
        valueÑomparisonVvV(vec, vec, i);
        valueÑomparisonAvA(arr, arr, i);
        // Sort the vector and array
        sumV += sortVector(vec, i);
        sumA += sortArray(arr, i);

    }
    std::cout << "Result Time taken to sort the vector: " << sumV / 50 << "s" << std::endl;
    std::cout << "Result Time taken to sort the array: " << sumA / 50 << "s" << std::endl;
}

*/