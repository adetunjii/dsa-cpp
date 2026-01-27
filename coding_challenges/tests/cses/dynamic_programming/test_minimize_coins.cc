#include <gtest/gtest.h>
#include <vector>
#include <cses.h>

TEST(TestCses, TestMinimizeCoins) {
	std::vector<int> coins = {1, 5, 7};
	ASSERT_EQ(3, cses::minimizeCoins(coins, 11));
}