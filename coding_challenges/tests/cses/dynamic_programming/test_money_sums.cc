#include <gtest/gtest.h>
#include <vector>
#include <cses.h>

TEST(TestCses, TestMoneySums) {
    std::vector<int> coins = {4, 2, 5, 2};
    std::vector<int> res = {2, 4, 5, 6, 7, 8, 9, 11, 13};

    ASSERT_EQ(res, cses::moneySums(coins));
}