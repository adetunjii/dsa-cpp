#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size(), sum = 0, found = 0;
        unordered_map<int, int> m;

        for (int num : nums) {
            sum += num;
            if (sum == k) found += 1;

            if (m.count(sum-k) > 0) {
                found += m[sum-k];
            }

            m[sum] += 1;
        }
        return found;
    }
};