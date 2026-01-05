#include <iostream>
#include <vector>
#include <ranges>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int N = cost.size();

        if (N < 2) return cost[0];
        if (N < 3) return std::min(cost[0], cost[1]);

        std::vector<int> dp(N+1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i : std::views::iota(2, N+1)) {
            dp[i] = std::min((cost[i - 1] + dp[i - 1]), (cost[i-2] + dp[i-2]));
        }  

        return dp[N];
    }
};