#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

namespace dp {
bool canPartition(std::vector<int>& nums) {
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    if (total & 1 > 0) {
        return false;
    }

    int target = total >> 1;

    std::vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int cap = target + 1; cap >= num; cap--) {
            dp[cap] = dp[cap] || dp[cap - num];
        }
    }
    return dp[target];
}

bool canPartitionBitset(std::vector<int>& nums) {
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    if (total & 1 > 0) {
        return false;
    }

    int target = total >> 1;

    std::vector<bool> dp(target + 1, false);

    std::bitset<10001> bit(1);

    for (int num : nums) {
        bit |= bit << num;
    }

    return bit[target];
}
} // namespace dp