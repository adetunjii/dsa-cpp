#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mp = INT_MIN, N = nums.size();
        int cur = 1;

        for(int num : nums) {
            cur *= num;
            mp = max(mp, cur);

            if (cur == 0) { // start a new subarray
                cur = 1;
            }
        }

        cur = 1;
        for (int i = N - 1; i >= 0; i--) {
            cur *= nums[i];
            mp = max(mp, cur);

            if (cur == 0)
                cur = 1;
        }
        return mp;
    }
};