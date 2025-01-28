#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0, N = nums.size();
        unordered_map<int, int> m;
        
        for (int num : nums) {
            m[num] += 1;
        }

        for (const auto& [k, v] : m) {
            if (m.count(k+1) > 0) {
                res = max(res, m[k] + m[k+1]);
            }
        }
        return res;
    }
};