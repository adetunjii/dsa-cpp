#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], minSum = nums[0], N = nums.size();
        int currentMin = nums[0], currentMax = nums[0], total = nums[0];

        for (int i = 1; i < N; i++) {
            currentMax = max(nums[i], currentMax + nums[i]);
            maxSum = max(maxSum, currentMax);
            currentMin = min(nums[i], currentMin + nums[i]);
            minSum = min(minSum, currentMin);

            total += nums[i];
        }

        if (maxSum < 0) return maxSum;
        return max(maxSum, total-minSum);
    }
};