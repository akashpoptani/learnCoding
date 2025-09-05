// raii_example.cpp
#include <iostream>
#include <fstream>

void writeToFile() {
    std::ofstream file("example.txt"); // opens file
    if (!file) {
        std::cerr << "Could not open file.\n";
        return;
    }
    file << "Hello, RAII!" << std::endl;
    // file automatically closed when destructor of ofstream runs here
}

int main() {
    writeToFile();
    std::cout << "Wrote to example.txt using RAII" << std::endl;
    return 0;
}
