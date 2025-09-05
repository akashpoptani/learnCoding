// references_example.cpp
#include <iostream>

int main() {
    int x = 10;
    int& ref = x; // ref is a reference (alias) to x
    std::cout << "Before: x = " << x << ", ref = " << ref << std::endl;
    ref = 20;    // changing ref changes x
    std::cout << "After: x = " << x << ", ref = " << ref << std::endl;
    return 0;
}
