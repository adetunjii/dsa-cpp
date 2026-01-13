#include <iostream>
#include <vector>
#include <span>
#include <ranges>

namespace dp {
      int houseRobber(std::span<int> nums) {
        int N = nums.size();
        std::vector<int> dp(N, 0);

        dp[0] = nums[0], dp[1] = std::max(nums[0], nums[1]);

        for (int i : std::views::iota(2, N)) {
            dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
       }

       return dp[N-1];
    }

    int houseRobberII(std::vector<int>& nums) {
        int N = nums.size();

        if (N == 1) return nums[0];
        if (N == 2) return std::max(nums[0], nums[1]);

        std::span<int> v1(nums.data(), N-1);
        std::span<int> v2(nums.data()+1, N-1);

        return std::max(houseRobber(v1), houseRobber(v2));
    }
}