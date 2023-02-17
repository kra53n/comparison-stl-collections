#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <chrono>

// Function to sort a given vector
double sortVector(std::vector<int>& vec, int i) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(), vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << i << "Time taken to sort the vector: " << diff.count() << "s" << std::endl;
    return diff.count();
}

// Function to sort a given array
double sortArray(std::array<int, 100000>& arr, int i) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << i <<  "Time taken to sort the array: " << diff.count() << "s" << std::endl;
    return diff.count();
}

int main() {
    
    double sumV = 0;
    double sumA = 0;
    for (int i = 0; i < 50; i++)
    {
        std::vector<int> vec;
        std::array<int, 100000> arr;
        // Generate 100,000 random values and store them in the vector and array
        for (int i = 0; i < 100000; i++) {
            int random_num = rand() % 100000;
            vec.push_back(random_num);
            arr[i] = random_num;
        }

        // Sort the vector and array
        sumV += sortVector(vec, i);
        sumA += sortArray(arr, i);
    }
    std::cout << "Result Time taken to sort the vector: " << sumV/50 << "s" << std::endl;
    std::cout << "Result Time taken to sort the array: " << sumA/50 << "s" << std::endl;
    return 0;
}