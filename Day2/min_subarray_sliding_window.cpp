#include <iostream>
#include <vector>
#include <climits>

int minSubArrayLen(int S, const std::vector<int>& arr) {
    int window_sum = 0;
    int min_length = INT_MAX;
    int start = 0;

    for (int end = 0; end < arr.size(); ++end) {
        window_sum += arr[end];

        // Shrink window from left while the sum is >= S
        while (window_sum >= S) {
            min_length = std::min(min_length, end - start + 1);
            window_sum -= arr[start];
            ++start;
        }
    }
    return (min_length == INT_MAX) ? 0 : min_length;
}

int main() {
    std::vector<int> arr = {2, 3, 8, 2, 4, 3};
    int S = 7;
    std::cout << "Smallest subarray length with sum >= " << S << " is " << minSubArrayLen(S, arr) << std::endl;
    // Output: 2 (subarray {4, 3})
    return 0;
}
