#include <iostream>
#include <vector>

class PhoneDirectory {
    static const int SIZE = 20;
    std::vector<int> table;
    std::vector<bool> occupied;
    std::vector<bool> removed;

public:
    PhoneDirectory() : table(SIZE, -1), occupied(SIZE, false) {}

    void insert(int number) {
        int index = number % SIZE;
        int startIndex = index;

        while (occupied[index] && table[index] != number) {
            index = (index + 1) % SIZE;
            if (index == startIndex) {
                std::cout << "Error: Directory full, cannot insert " << number << std::endl;
                return;
            }
        }

        table[index] = number;
        occupied[index] = true;
    }

    void remove(int number) {
        int index = number % SIZE;
        int startIndex = index;

        while (occupied[index]) {
            if (table[index] == number) {
                table[index] = -1;
                occupied[index] = false;
                std::cout << "Removed " << number << std::endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == startIndex) break;
        }
        std::cout << number << " not found for removal." << std::endl;
    }

    bool exists(int number) {
        int index = number % SIZE;
        int startIndex = index;

        while (occupied[index]) {
            if (table[index] == number) {
                return true;
            }
            index = (index + 1) % SIZE;
            if (index == startIndex) break;
        }
        return false;
    }
};

// Example usage:
int main() {
    PhoneDirectory dir;

    dir.insert(10);
    dir.insert(30);
    dir.insert(50);

    std::cout << "Exists 10? " << (dir.exists(10) ? "Yes" : "No") << std::endl;
    std::cout << "Exists 20? " << (dir.exists(20) ? "Yes" : "No") << std::endl;

    dir.remove(30);
    std::cout << "Exists 30? " << (dir.exists(30) ? "Yes" : "No") << std::endl;

    dir.insert(30);
    std::cout << "Exists 30? " << (dir.exists(30) ? "Yes" : "No") << std::endl;

    return 0;
}
