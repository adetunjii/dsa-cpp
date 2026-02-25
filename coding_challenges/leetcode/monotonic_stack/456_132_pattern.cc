#include <vector>
#include <utility>
#include <stack>
#include <ranges>

namespace monotonic_stack {
    bool find132pattern(std::vector<int>& nums) {
        int N = nums.size();
        
        if (N == 0) return false;

        std::stack<std::pair<int, int>> st;

        int currentMin = nums[0];

        for (int i : std::views::iota(0, N)) {
            int k = nums[i];

            while(!st.empty() && k >= st.top().first) {
                st.pop();
            }

            if (!st.empty() && k > st.top().second) {
                return true;
            }

            st.push({k, currentMin});
            currentMin = std::min(currentMin, k);
        }

        return false;
    }
}