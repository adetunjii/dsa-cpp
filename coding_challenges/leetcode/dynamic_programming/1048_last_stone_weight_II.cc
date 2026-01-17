#include <iostream>
#include <vector>
#include <ranges>
#include <numeric>

namespace dp {
    int lastStoneWeightII(std::vector<int>& stones) {
           int N = stones.size();
        if(N < 2) return 0;

        int total = std::accumulate(stones.begin(), stones.end(), 0);
        int target = total/2;

        std::vector<int> dp(target+1, 0);

        for (int i : std::views::iota(0, N)) {
            for (int c = target; c >= stones[i]; c--) {
                dp[c] = std::max(dp[c], dp[c-stones[i]] + stones[i]);
            }
        }

        return total - (2*dp[target]);
    }
}