#include <limits.h>
#include <vector>

int minSubArrayLen(int target, std::vector<int>& nums) {
    int N = nums.size();
    if (N == 0)
        return 0;

    int minLength = INT_MAX;

    int left = 0;
    int right = 0;

    int current = 0;

    while (left <= right && right < N) {
        current += nums[right];

        if (current == target) {
            return right - left + 1;
        }

        while (current >= target) {
            minLength = std::min(minLength, right - left + 1);
            current -= nums[left];
            left += 1;
        }

        right += 1;
    }

    return minLength == INT_MAX ? 0 : minLength;
};