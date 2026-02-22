#include <vector>
#include <utility>
#include <stack>

namespace monotonic_stack {
    bool find132pattern(std::vector<int>& nums) {
        // 1. stack is a monotonically decreasing stack that holds currentNumber and the min encountered so far
        int N = nums.size();
        std::stack<std::pair<int, int>> st;

        int currentMin = nums[0];

        for (int i = 1; i < N; i++) {
            while(!st.empty() && nums[i] >= st.top().first) {
                st.pop();
            }

            if (!st.empty() && nums[i] > st.top().second) {
                return true;
            }

            st.push({nums[i], currentMin});
            currentMin = std::min(currentMin, nums[i]);
        }

        return false;
    }
}