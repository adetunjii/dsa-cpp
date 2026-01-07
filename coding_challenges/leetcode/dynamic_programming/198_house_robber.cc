#include <iostream>
#include <vector>
#include <ranges>

class Solution {
public:
    int rob(std::vector<int>& nums) {   
        int N = nums.size();

        if (N == 1) return nums[0];
        if (N == 2) return std::max(nums[0], nums[1]);

        std::vector<int> dp(N, 0);
        dp[0] = nums[0], dp[1] = std::max(nums[0], nums[1]);

        for (int i : std::views::iota(2, N)) {
            dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        return dp[N-1];
    }
};