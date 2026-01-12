#include <iostream>
#include <vector>
#include <ranges>

namespace dp {

    int climbStairsII(int N, std::vector<int>& coins) {
        if (N == 0) return 0;

        std::vector<int> dp(N+1, 0);
        dp[0] = 0;

        for (int i : std::views::iota(1, N+1)) {
            int val = dp[i-1] + 1;
            if (val > 1) val = std::min(val, dp[i-2] + 4);
            if (val > 2) val = std::min(val, dp[i-3] + 9);

            dp[i] = val + coins[i-1];
        }

        return dp[N];
    }

    int climbStairsII_BruteForce(int N, std::vector<int>& costs) {
        if (N == 0) return 0;

        std::vector<int> dp(N+1, INT_MAX);
        dp[0] = 0, dp[1] = costs[0] + 1;

        for (int i : std::views::iota(2, N+1)) {
            for (int j : std::views::iota(1, 4)) {
                if (i - j >= 0) {
                    int cost_at_i = costs[i-1] + (j * j);
                    dp[i] = std::min(dp[i], cost_at_i + dp[j]);
                }
            }
        }

        return dp[N];
    }
}