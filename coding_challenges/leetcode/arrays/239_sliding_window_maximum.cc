#include <iostream>
#include <vector>
#include <set>
#include <ranges>
#include <deque>

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

    vector<int> maxSlidingWindowDeque(vector<int>& nums, int k) {
        int N = nums.size();

        deque<int> q;
        vector<int> res;
        res.reserve(N - k + 1);

        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        res.push_back(nums[q.front()]);

        for (int i = k; i < N; i++) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            
            q.push_back(i);

            if (!q.empty() && q.front() == i-k) {
                q.pop_front();
            }
            
            res.push_back(nums[q.front()]);
        }

        return res;
    }
};