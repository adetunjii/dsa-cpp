#include <iostream>
#include <vector>
#include <set>

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
};