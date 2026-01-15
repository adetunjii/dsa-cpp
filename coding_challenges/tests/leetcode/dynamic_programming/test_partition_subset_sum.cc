#include <gtest/gtest.h>
#include <vector>
#include <dp.h>

TEST(TestDp, TestPartitionSubsetSum){
    std::vector<int> nums = {1, 5, 11, 5};
    ASSERT_EQ(true, dp::canPartition(nums));
}