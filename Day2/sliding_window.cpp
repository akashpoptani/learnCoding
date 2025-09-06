#include <iostream>
#include <vector>

int maxSumSubarray(const std::vector<int>& arr, int k) {
    int window_sum = 0, max_sum = 0;
    for (int i = 0; i < k; ++i) {
        window_sum += arr[i];
    }
    max_sum = window_sum;
    for (int i = k; i < arr.size(); ++i) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }
    return max_sum;
}

int main() {
    std::vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    std::cout << "Max sum of subarray of size " << k << " is " << maxSumSubarray(arr, k) << std::endl;
    // Output: 9 (subarray {5,1,3})
    return 0;
}
