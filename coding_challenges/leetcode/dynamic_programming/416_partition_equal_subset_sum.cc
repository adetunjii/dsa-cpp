#include <iostream>
#include <vector>
#include <ranges>

namespace dp {
    bool canPartition(std::vector<int>& nums) {
        int N = nums.size();
        if (N < 2) return false;

        int total = 0;
        for (auto& num : nums) {
            total += num;
        }

        if (total % 2 != 0) return false;

        int target = total/2;

        // can be used to replace code below        
        // std::vector<int>dp(target+1, 0);
        // for (int i : std::views::iota(0, N)) {
        //     for (int cap = target; cap >= 0; cap--) {
        //         if (cap >= nums[i]) {
        //             dp[cap] = std::max(dp[cap], dp[cap-nums[i]] + nums[i]);
        //         }
        //     }
        // }
        // return dp[target] == target;

        std::vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int i : std::views::iota(0, N)) {
            for (int cap : std::views::iota(1, target+1) | std::views::reverse) {
                if (cap >= nums[i]) {
                    dp[cap] = dp[cap] || nums[i] + dp[cap - nums[i]];
                }
            }
        }

        return dp[target];
    }
}