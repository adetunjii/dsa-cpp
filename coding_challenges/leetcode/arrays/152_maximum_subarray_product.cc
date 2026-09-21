#include <iostream>
#include <vector>
#include <algorithm>

namespace dp{
int maxProduct(std::vector<int>& nums) {
    int mp = INT_MIN, N = nums.size();
    int cur = 1;

    for(int num : nums) {
        cur *= num;
        mp = std::max(mp, cur);

        if (cur == 0) { // start a new subarray
            cur = 1;
        }
    }

    cur = 1;
    for (int i = N - 1; i >= 0; i--) {
        cur *= nums[i];
        mp = std::max(mp, cur);

        if (cur == 0)
            cur = 1;
    }
    return mp;
}

int maxProduct(std::vector<int>& nums) {
    int N = nums.size();

    if (N == 0) return 0;
    if (N == 1) return nums[0];

    int maxProd = nums[0];
    int minProd = nums[0];

    int res = nums[0];

    for (int i = 1; i < N; i++) {
        int prev = maxProd;
        maxProd = std::max(nums[i], std::max(maxProd * nums[i], minProd * nums[i]));
        minProd = std::min(nums[i], std::min(minProd * nums[i], prev * nums[i]));

        res = std::max(res, maxProd);
    }

    return res;
}
};
