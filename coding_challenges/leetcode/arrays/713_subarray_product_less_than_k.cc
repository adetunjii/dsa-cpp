#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int N = nums.size();
        int l = 0, r = 0, count = 0, prefix = 1;

        while (r < N) {
            prefix *= nums[r];
            while (l <= r && prefix >= k) {
                prefix /= nums[l];
                l += 1;
            }
            count += r-l+1;
            r += 1;
        }
        return count;
    }
};