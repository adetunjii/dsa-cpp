#include <iostream>
#include <vector>
#include <ranges>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return N;

        std::vector<int> dp(N, 1);

        for (int i : std::views::iota(1, N)) {
            for (int j : std::views::iota(0, i)) {
                if (nums[i] > nums[j] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};