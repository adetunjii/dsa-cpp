#include <iostream>
#include <vector>
#include <unordered_set>
#include <span>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int longest = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for (int num : nums) {
            if (s.find(num - 1) == s.end()) {
                int length = 1;

                while (s.find(num+1) != s.end()) {
                    length += 1;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
