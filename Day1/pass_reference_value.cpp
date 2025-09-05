#include <iostream>

// Pass by value: modifies only local copy
void passByValue(int x) {
    x = 42; // change only local copy
}

// Pass by reference: modifies original variable
void passByReference(int &x) {
    x = 42; // change affects caller's variable directly
}

int main() {
    int a = 10;

    passByValue(a);
    std::cout << "After passByValue: a = " << a << std::endl;  // prints 10

    passByReference(a);
    std::cout << "After passByReference: a = " << a << std::endl; // prints 42

    return 0;
}
