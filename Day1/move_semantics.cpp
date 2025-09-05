// move_semantics_example.cpp
#include <vector>
#include <iostream>
#include <utility> // for std::move

std::vector<int> createVector() {
    std::vector<int> v = {1, 2, 3};
    return v; // moves vector instead of copying (RVO)
}

int main() {
    std::vector<int> v1 = createVector(); // move constructor used
    std::vector<int> v2 = std::move(v1);  // explicitly move v1 into v2 - Move Semantics

    std::cout << "Contents of v2: ";
    for (int n : v2) std::cout << n << ' ';
    std::cout << std::endl;

    std::cout << "v1 size after move: " << v1.size() << std::endl; // usually 0 after move
    return 0;
}
