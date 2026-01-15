#include <vector>
#include <ranges>

namespace dp {
    int coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int N = coins.size();
        if (N < 1) return -1;

        std::vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for (int i : std::views::iota(0, N)) {
            for (int c = coins[i]; c <= amount; c++) {
                dp[c] = std::min(dp[c], dp[c - coins[i]] + 1);
            }
        }

        return dp[amount];
    }
}