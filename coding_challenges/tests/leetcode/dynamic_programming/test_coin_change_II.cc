#include <gtest/gtest.h>
#include <vector>
#include <dp.h>

TEST(TestDp, TestCoinChangeII) {
    std::vector<int> coins = {1,2,5};
    ASSERT_EQ(4, dp::coinChangeII(5, coins));
}