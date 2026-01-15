#include <vector>
#include <ranges>

namespace dp {
    int coinChangeII(int amount, std::vector<int>& coins) {
        int N = coins.size();
        if (N == 0) return 0;

        std::vector<int> dp(amount+1, 0);
        dp[0] = 1;

        for (int i : std::views::iota(0, N)) {
            for (int cap = coins[i]; cap <= amount; cap++) {
                dp[cap] += dp[cap-coins[i]];
            }
        }

        return dp[amount];
    }
}