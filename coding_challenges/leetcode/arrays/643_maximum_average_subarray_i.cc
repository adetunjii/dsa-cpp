#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int N = nums.size();
        if(N > k) return 0;

        int l = 0, r = 0;

        double m = 0, sum = 0;

        while (r++ < k) {
            sum += nums[r];
        }

        m = sum;

        while (r < N) {
            sum += nums[r] - nums[l];
            m = max(m, sum);
            l++;
            r++;
        }

        return m/k;
    }
};