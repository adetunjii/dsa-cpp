// Question: 
// Write a function sumPossible that takes in an amount and a vector of positive numbers. 
// The function should return a boolean indicating whether or not it is possible to create 
// the amount by summing numbers of the vector. You may reuse numbers of the vector as many 
// times as necessary.

// You may assume that the target amount is non-negative.

#include <iostream>
#include <vector>
#include <ranges>

namespace dp {
    bool sumPossible(int amount, std::vector<int> nums) {
        if (amount == 0) return true;
        
        int N = nums.size();
        if (N == 1) return nums[0] == amount;

        std::vector<int> dp(amount+1, false);
        dp[0] = true;

        for (int i : std::views::iota(0, N)) {
            for (int j = nums[i]; j <= amount; j++) {
                if (dp[j - nums[i]]) {
                    dp[j] = true;
                }
            }
        }
        
        return dp[amount];
    }
}