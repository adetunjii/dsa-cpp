#pragma once

#include <vector>

namespace dp {

    // House Robber
    int rob(std::vector<int>& nums);

    // House Robber II
    int houseRobberII(std::vector<int>& nums);

    // Partition Subset Sum
    bool canPartition(std::vector<int>& nums);

    // Coin Change
    int coinChange(std::vector<int>& coins, int amount);
}