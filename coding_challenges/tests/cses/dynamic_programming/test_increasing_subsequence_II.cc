#include <gtest/gtest.h>
#include <vector>
#include <cses.h>

TEST(TestCses, TestIncreasingSubsequenceII) {
    std::vector<int> nums = {2, 1, 3};
    ASSERT_EQ(5, cses::increasingSubsequenceII(nums));
}