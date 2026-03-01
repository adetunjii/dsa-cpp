#include <vector>
#include <deque>

namespace monotonic_queue {
    // implementation uses a sliding window + 2 monotonic deques technique.
    // The front of the minimum deque always holds the minimum of the current subarray
    // The front of the maximum deque always holds the maximum of the current subarray
    int longestSubarray(std::vector<int>& nums, int limit) {
        int N = nums.size();
        if (N == 0) return 0;

        std::deque<int> minQueue, maxQueue;

        int left = 0;

        int maxLen = 0;

        for (int right = 0; right < N; right++) {
            while (!minQueue.empty() && nums[right] < minQueue.back()) {
                minQueue.pop_back();
            }

            while (!maxQueue.empty() && nums[right] > maxQueue.back()) {
                maxQueue.pop_back();
            }

            minQueue.push_back(nums[right]);
            maxQueue.push_back(nums[right]);

            while (maxQueue.front() - minQueue.front() > limit) {
                if (nums[left] == maxQueue.front()) {
                    maxQueue.pop_front();
                }

                if (nums[right] == minQueue.front()) {
                    minQueue.pop_front();
                }

                left += 1;
            }

            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
}