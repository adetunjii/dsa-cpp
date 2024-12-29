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

        unordered_set<int> s(nums.begin(), nums.end()); // eliminates duplicates

        for (int i = 0; i < nums.size(); i++) {
           if (s.find(nums[i] - 1) == s.end()) {
                int length = 1;
                while(s.find(nums[i]+length) != s.end()) {
                    length += 1;
                }

                longest = max(longest, length);
           }
        }
        return longest; 
    }

    int longestConsecutiveB(vector<int>& nums) {
        if (nums.empty()) return 0;
        int longest = 0, length = 1, last_seen = INT_MIN;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++ ) {
            if (nums[i]-1 == last_seen) {
                last_seen = nums[i];
                length += 1;
            } 
            if (nums[i] != last_seen) {
                length = 1;
                last_seen = nums[i];
            }
            longest = max(longest, length);
        }

        return longest;
    }
};
