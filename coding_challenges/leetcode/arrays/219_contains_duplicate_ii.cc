#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

class Solution {
public:
	bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
		std::unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); ++i) {
			if (m.count(nums[i]) > 0) {
				if (abs(m[nums[i]] - i) <= k) return true;
				// replace existing idx;
				else m[nums[i]] = i;
			}
			m[nums[i]] = i;
		}
		return false;
	} 
};