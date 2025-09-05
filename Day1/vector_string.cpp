// vector_string_example.cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> vec = {1, 2, 3};
    vec.push_back(4); // add element

    std::string greeting = "Hello";
    greeting += ", world!";

    std::cout << greeting << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector contents: ";
    for (int n : vec) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    return 0;
}
