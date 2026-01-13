#include <gtest/gtest.h>
#include <vector>

namespace dp {
    int climbStairsII(int N, std::vector<int>& costs);
}

TEST(TestDP, TestClimbingStairsII) {
    std::vector<int> costs = {1, 2, 3, 4};
    ASSERT_EQ(13, dp::climbStairsII(4, costs));
}