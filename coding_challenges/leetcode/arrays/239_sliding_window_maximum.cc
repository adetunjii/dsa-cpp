#include <iostream>
#include <vector>
#include <set>
#include <ranges>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> res;

        for (int i = 0; i < k; i++) { ms.insert(nums[i]); }

        for (int i = k; i < nums.size(); i++) {
            // multiset inserts in ascending order by default whilst allowing duplicates to exist
            res.push_back(*ms.rbegin()); // append the element at the end of the multiset for this current window - rbegin(reverse begin)
            ms.erase(ms.find(nums[i-k])); // shrink the window
            ms.insert(nums[i]); // expand the window
        }
        res.push_back(*ms.rbegin()); // find the max value again since we're only inserting after after we've handled previous window.
        return res;
    }


    vector<int> maxSlidingWindowBruteForce(vector<int>& nums, int k) {
        int N = nums.size();
        if (N == 0) return {};

        vector<int> res;

        int left = 0, right = k;

        while (right <= N) {
            int currentMin = INT_MIN;
            
            int i = left; 
            for (int i : std::views::iota(left, right)) {
                currentMin = max(currentMin, nums[i]);
            }

            res.push_back(currentMin);

            left += 1;
            right += 1;
        }

        return res;
    }
};