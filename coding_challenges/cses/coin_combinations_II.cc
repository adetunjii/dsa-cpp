#include <vector>
#include <ranges>

#define ll long long int

namespace cses {
	int coinCombinationII(std::vector<int>& coins, ll target) {
		int N = coins.size();

		ll M = 10e9 + 7;

		std::vector<int> dp(target+1, 0);
		dp[0] = 1;

		for (int coin : coins) {
			for (int c = coin; c <= target; c++) {
				dp[c] = (dp[c] + dp[c-coin]) % 7; 
			}
		}

		return dp[target];
	}
}