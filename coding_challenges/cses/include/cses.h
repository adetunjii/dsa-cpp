#pragma once

#ifndef ll
#define ll long long int
#endif

#include <vector>

namespace cses {
	// Dynamic programming - Dice Combination
	int diceCombination(int N);

	// Dynamic programming - Minimize coins
	int minimizeCoins(std::vector<int> coins, int target);	

	// Dynamic programming - Coin combinations I
	int coinCombinationI(std::vector<int>& coins, ll target);
}