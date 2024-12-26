#include <iostream>
#include <vector>
#include <unordered_set>
#include <span>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        // find the smallest element in the set
        for (int num : nums) {
            if (s.find(num-1) == s.end()) { // i.e there is no smaller element
                int length = 1; 

                while(s.find(num+length) != s.end()) { // while there are consecutive elements, update length;
                    length += 1;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }


};

int main() {
    Solution sol;
    vector<int> nums = {0,3,2,5,4,6,1,1};
    cout << sol.longestConsecutive(nums) << endl;;
}