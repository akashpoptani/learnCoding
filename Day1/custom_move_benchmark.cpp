// custom_move_benchmark.cpp
#include <iostream>
#include <vector>
#include <chrono>

class BigData {
public:
    std::vector<int> data;

    // Constructor
    BigData(size_t size) : data(size, 42) {}

    // Copy constructor
    BigData(const BigData& other) : data(other.data) {
        std::cout << "Copy constructor called\n";
    }

    // Move constructor
    BigData(BigData&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Move constructor called\n";
    }

    // Copy assignment
    BigData& operator=(const BigData& other) {
        std::cout << "Copy assignment called\n";
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    // Move assignment
    BigData& operator=(BigData&& other) noexcept {
        std::cout << "Move assignment called\n";
        if (this != &other) {
            data = std::move(other.data);
        }
        return *this;
    }
};

// Helper function to measure execution time of a copy
void measureCopy(const BigData& b) {
    auto start = std::chrono::high_resolution_clock::now();
    BigData copy = b;  // copy constructor
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy took " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() 
              << " microseconds\n";
}

// Helper function to measure execution time of a move
void measureMove(BigData&& b) {
    auto start = std::chrono::high_resolution_clock::now();
    BigData moved = std::move(b);  // move constructor
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Move took " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() 
              << " microseconds\n";
}

void measureCopyAssignment(BigData& target, const BigData& source) {
    auto start = std::chrono::high_resolution_clock::now();
    target = source;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy assignment took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds\n";
}

void measureMoveAssignment(BigData& target, BigData&& source) {
    auto start = std::chrono::high_resolution_clock::now();
    target = std::move(source);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Move assignment took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds\n";
}

int main() {
    BigData big(1000000); // 1 million elements

    std::cout << "Measuring copy:\n";
    measureCopy(big);

    std::cout << "Measuring move:\n";
    measureMove(std::move(big));
    std::cout << "-------------------------------------------------------------------------\n";

    BigData big1(1000000);  // Source data with 1 million elements
    BigData big2(500000);   // Target data with 500k elements

    std::cout << "Measuring copy assignment:\n";
    measureCopyAssignment(big2, big1);

    std::cout << "Measuring move assignment:\n";
    measureMoveAssignment(big2, std::move(big1)); // big1 moved-from
    std::cout << "-------------------------------------------------------------------------\n";

    big1 = BigData(1000000);  // Reinitialize big1 to measure assignment now that it’s empty
    big2 = BigData(1000000);  // Reinitialize big2 to measure assignment now that it’s empty

    std::cout << "Measuring copy assignment:\n";
    measureCopyAssignment(big2, big1);

    std::cout << "Measuring move assignment:\n";
    measureMoveAssignment(big2, std::move(big1)); // big1 moved-from
    std::cout << "-------------------------------------------------------------------------\n";

    return 0;
}
