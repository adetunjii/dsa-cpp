#include <iostream>
#include <vector>
#include <ranges>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n+1, 0);
        if (n < 3) return n;

        for(int i : std::views::iota(2, n+1)) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};