#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequentElement(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) m[num] += 1;

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& [key, val] : m) {
           bucket[val].push_back(key); 
        }

        vector<int> res;
        for(int j = bucket.size() - 1; j >= 0; j--) {
            for (int n : bucket[j])
                res.push_back(n);
                if (res.size() == k) return res;
        }
        return {};
    }
};