#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long m = 0, sum = 0;
        bitset<100001> window(0);
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            int cur = nums[r];

            while(window[cur] ||  r - l + 1 > k) {
                window[nums[l]] = false;
                sum -= nums[l];
                l += 1;
            }

            sum += cur;
            window[cur] = true;

            if (r-l+1 == k) {
                m = max(sum, m);
            }
        }
        return m;
    }
};