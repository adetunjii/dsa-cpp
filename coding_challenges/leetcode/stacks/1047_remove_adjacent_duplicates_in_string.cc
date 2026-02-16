#include <vector>
#include <string>

namespace stack {
    std::string removeDuplicates(std::string s) {
        int N = s.size();

        if (N == 0) return "";

        std::vector<char> st;

        st.push_back(s[0]);

        for (int i = 1; i < N; i++) {
            if (!st.empty() && (st[st.size() - 1] == s[i])) {
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }
        }

        std::string res;

        for (auto& c : st) {
            res += c;
        }

        return res;
    }
}