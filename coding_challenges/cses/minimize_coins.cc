#include <iostream>
#include <vector>
#include <ranges>

namespace cses {
	int minimizeCoins(std::vector<int> coins, int target) {
		int N = coins.size();
		if (N == 0 || target == 0) return 0;

		std::vector<int> dp(target+1, target+1);
		dp[0] = 0;

		for (int coin : coins) {
			for (int c = coin; c <= target; c++) {
				dp[c] = std::min(dp[c], dp[c-coin] + 1);
			}
		}

		return dp[target] == target+1 ? -1 : dp[target];
	}
}