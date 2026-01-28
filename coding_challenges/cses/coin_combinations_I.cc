#include <iostream>
#include <vector>
#include <ranges>

#define ll long long int

namespace cses {
	long long coinCombinationI(std::vector<int>& coins, ll target) {
		int N = coins.size();
		ll M = 10e9 + 7;

		std::vector<ll> dp(target+1, 0);
		dp[0] = 1;

		for (int i : std::views::iota(1, target+1)) {
			for (int coin : coins) {
				if (i >= coin) {
					dp[i] = (dp[i] + dp[i-coin]) % M;
				}
			}
		}

		return dp[target];
	}
}