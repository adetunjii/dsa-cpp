#include <gtest/gtest.h>
#include <vector>
#include <dp.h>

TEST(TestDP, TestBestTimeToBuyAndSellStock) {
    std::vector<int> prices = {7,1,5,3,6,4};
    ASSERT_EQ(5, dp::maxProfit(prices));
}