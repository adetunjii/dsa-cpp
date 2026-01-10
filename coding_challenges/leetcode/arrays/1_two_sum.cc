#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
      unordered_map<int, int> m;
      int N = nums.size();
      for (int i = 0; i < N; i++){
        int diff = target - nums[i];
        if (m.count(diff) > 0) {
          return vector<int>{m[diff], i};
        }
        
        m[nums[i]] = i;
    }
      return {};
    }
};
