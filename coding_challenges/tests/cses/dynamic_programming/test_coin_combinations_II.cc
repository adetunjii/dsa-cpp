#include <gtest/gtest.h>
#include <vector>
#include <cses.h>

TEST(TestCses, TestCoinCombinationII) {
	std::vector<int> coins = {2, 3, 5};
	ASSERT_EQ(3, cses::coinCombinationII(coins, 9));
}