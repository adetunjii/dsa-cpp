#include <gtest/gtest.h>
#include <vector>
#include <dp.h>

TEST(TestDp, TestLastStoneWeightII) {
    std::vector<int> stones = {2,7,4,1,8,1};
    ASSERT_EQ(1, dp::lastStoneWeightII(stones));
}