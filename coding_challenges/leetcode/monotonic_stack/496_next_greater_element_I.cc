#include <vector>
#include <unordered_map>
#include <stack>

namespace monotonic_stack {
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::stack<int> st;
        std::unordered_map<int, int> m;
        
        std::vector<int> res(nums1.size(), -1);

        for (auto& num : nums2) {
            if (st.empty() || num < st.top()) {
                st.push(num);
            } else {
                while(!st.empty() && num > st.top()) {
                    m[st.top()] = num;
                    st.pop();
                }

                st.push(num);
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (m.count(nums1[i]) != 0) {
                res[i] = m[nums1[i]];
            }
        }

        return res;
    }
}