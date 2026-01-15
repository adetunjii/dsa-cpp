#include <gtest/gtest.h>
#include <vector>
#include <dp.h>

TEST(TestDp, TestCoinChange) {
    std::vector<int> coins = {1, 2, 5};
    ASSERT_EQ(3, dp::coinChange(coins, 11));
}