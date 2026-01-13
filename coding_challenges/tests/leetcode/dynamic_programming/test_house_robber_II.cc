#include <gtest/gtest.h>
#include <vector>
#include <dp.h>

TEST(TestDP, TestHouseRobberII) {
    std::vector<int> nums = {2,3,2};
    ASSERT_EQ(3, dp::houseRobberII(nums));
}