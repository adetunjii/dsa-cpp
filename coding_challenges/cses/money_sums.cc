#include <iostream>
#include <ranges>
#include <vector>
#include <set>
#include <numeric>

namespace cses {
    std::vector<int> moneySums(std::vector<int>& coins) {
        int N = coins.size();

        int total = std::accumulate(coins.begin(), coins.end(), 0);

        std::vector<int> dp(total+1, false);
        dp[0] = true;

        for (int i : std::views::iota(0, N)) {
            for (int c = total; c >= coins[i]; c--) {
                if (dp[c - coins[i]]) {
                    dp[c] = true;
                }
            }
        }

        std::vector<int> result;
        for (int i = 1; i < total+1; i++) {
            if (dp[i]) result.push_back(i);
        }

        return result;
    }
}