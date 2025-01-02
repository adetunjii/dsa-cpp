#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1) return s.length();
        int l = 0, r = 0, N = s.length(), longest = 0;
        unordered_map<char, int> m;
        while (l <= r && r < N) {
            if (m.count(s[r]) != 0) {
                l = max(m[s[r]] + 1, l);
            }

            longest = max(longest, r-l+1);
            m[s[r]] = r;
            r += 1;
        }

        return longest;
    }
};