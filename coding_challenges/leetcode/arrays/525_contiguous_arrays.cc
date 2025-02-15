#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size(), maxLen = 0, sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;

        for (int i = 0; i < N; i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (m.count(sum) > 0) maxLen = max(maxLen, i - m[sum]);
            else m[sum] = i;
        }
        return maxLen;
    }
}