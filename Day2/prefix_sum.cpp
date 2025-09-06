#include <iostream>
#include <vector>

class PrefixSum {
    std::vector<int> prefix;

public:
    PrefixSum(const std::vector<int>& arr) {
        prefix.resize(arr.size() + 1, 0);
        for (size_t i = 0; i < arr.size(); ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
    }

    // Returns sum of elements from index l (inclusive) to r (exclusive)
    int query(int l, int r) const {
        return prefix[r] - prefix[l];
    }
};

int main() {
    std::vector<int> arr = {2, 4, 5, 7, 8};
    PrefixSum ps(arr);

    std::cout << "Sum of [1, 4): " << ps.query(1, 4) << std::endl; // 4+5+7=16
    std::cout << "Sum of [0, 5): " << ps.query(0, 5) << std::endl; // 2+4+5+7+8=26
    return 0;
}