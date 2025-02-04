#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == 0 && nums[i-1] == 0) return true;
            sum += nums[i];
            if(m.find(sum%k) == m.end()) {
                m[sum%k] = i;
            } else if (i - m[sum%k] >= 2) {
                return true;
            }
        }
        return false;
    }
};