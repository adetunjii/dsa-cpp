#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (m.count(diff) > 0) return {m[diff], i};
            m[nums[i]] = i;
        }

        return {};
    }
};