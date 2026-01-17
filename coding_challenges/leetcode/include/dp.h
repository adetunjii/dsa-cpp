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

    // coin change II
    int coinChangeII(int amount, std::vector<int>& coins);

    // Best time to buy and sell stock
    int maxProfit(std::vector<int>& prices);

    // Best time to buy and sell stock II
    int maxProfitII(std::vector<int>& prices);

    // Last Stone Weight II
    int lastStoneWeightII(std::vector<int>& stones);
}