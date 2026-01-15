#include <gtest/gtest.h>
#include <vector>
#include <dp.h>

TEST(TestDP, TestBestTimeToBuyAndSellStockII) {
    std::vector<int> prices = {7,1,5,3,6,4};
    ASSERT_EQ(7, dp::maxProfitII(prices));
}