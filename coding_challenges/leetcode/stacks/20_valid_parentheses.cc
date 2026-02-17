#include <iostream>
#include <string>
#include <stack>

using namespace std;

namespace stack{
    bool isValid(string s) {
        unordered_map<char, char> m = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
        };

        stack<char> st;
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