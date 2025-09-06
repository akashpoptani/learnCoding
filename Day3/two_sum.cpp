#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numToIndex;
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numToIndex.find(complement) != numToIndex.end()) {
            return {numToIndex[complement], i};
        }
        numToIndex[nums[i]] = i;
    }
    
    return {}; // No solution found, should not happen if input guaranteed to have a solution
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto result = twoSum(nums, target);
    if (!result.empty()) {
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    } else {
        std::cout << "No two sum solution found." << std::endl;
    }
    
    return 0;
}
