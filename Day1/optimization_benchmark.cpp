// optimization_benchmark.cpp
#include <iostream>
#include <chrono>
#include <vector>

int main() {
    constexpr int size = 100000000; // 100 million
    std::vector<int> vec(size, 1);
    long long sum = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size; ++i) {
        sum += vec[i];
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Duration: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    return 0;
}
