#include <iostream>
#include <string>
#include <stack>

namespace stack{
    bool isValid(std::string s) {
        unordered_map<char, char> m = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
        };

        std::stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && m[st.top()] == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};