#include <iostream>
#include <vector>
#include <ranges>

namespace cses {
	// Bounded-knapsack problem
	int diceCombination(int N) {
		if (N == 0) return 0;

		std::vector<long long > dp(N+1, 0);
		dp[0] = 1;

		int M = 10e9+7;

		for (int i : std::views::iota(1, N+1)) {
			for(int c : std::views::iota(1, 7)) {
				if (i >= c) {
					dp[i] = (dp[i] + dp[i-c]) % M;
				}
			}
		}

		return dp[N];
	}
}