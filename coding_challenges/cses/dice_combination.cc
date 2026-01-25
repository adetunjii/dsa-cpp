#include <iostream>
#include <vector>
#include <ranges>

namespace dp {
    int diceCombination(int n, int target) {
        std::vector<int> dp(target+1, 0);
        dp[0] = 1;

        int M = 10e9 + 7;

        for (int i : std::views::iota(1, n)) {
            for (int c = i; c <= target; c++) {
                dp[c] = (dp[c] + dp[c-i]) % M;
            }
        }

        return dp[target];
    }
}