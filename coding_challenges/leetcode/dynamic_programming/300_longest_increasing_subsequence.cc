#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

namespace dp {

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

int lengthOfLISOptimized(std::vector<int>& nums) {
    int N = nums.size();
    std::vector<int> dp;
    dp.push_back(nums[0]);

    for (int i : std::views::iota(1, N)) {
        if (nums[i] > dp.back()) {
            dp.push_back(nums[i]);
        } else {
            int lower = std::lower_bound(dp.begin(), dp.end(), nums[i]);
            *lower = nums[i];
        }
    }

    return dp.size();
}

int solveLISWithGreedy(std::vector<int>& nums) {
    int N = nums.size();
    if(N < 2) return N;

    std::vector<int> sub;

    for (int num : nums) {
        if (sub.empty() || sub[sub.size() - 1] < num) {
            sub.push_back(num);
        } else {
            auto lower = lower_bound(sub.begin(), sub.end(), num);
            *lower = num;
        }
    }

    return sub.size();
}
}