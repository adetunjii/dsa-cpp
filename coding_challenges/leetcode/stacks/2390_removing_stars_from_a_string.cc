#include <vector>

namespace stack {
    std::string removeStars(std::string s) {
        int N = s.size();
        if (N == 0) return "";
        
        std::vector<char> st;

        for (auto& c : s) {
            if (!st.empty() && c == '*') {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        } 

        std::string res;

        for (auto& c : st) res += c;

        return res;
    }
}