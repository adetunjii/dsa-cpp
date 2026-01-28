#include <gtest/gtest.h>
#include <vector>
#include <cses.h>

TEST(TestCses, TestCoinCombination) {
	std::vector<int> coins = {2, 3, 5};
	ASSERT_EQ(8, cses::coinCombinationI(coins, 9));
}