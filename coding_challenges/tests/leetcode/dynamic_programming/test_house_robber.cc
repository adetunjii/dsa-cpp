#include <gtest/gtest.h>
#include <vector>
#include <dp.h>

TEST(TestDp, TestHouseRobber) {
    std::vector<int> nums = {1,2,3,1};
    ASSERT_EQ(4, dp::rob(nums));
}