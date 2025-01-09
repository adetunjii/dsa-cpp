#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
       int cur_s = 0;
       int cur_t = 0;

        while (cur_t < t.size()) {
            if (s[cur_s] == t[cur_t]) {
                cur_s += 1;
            }
            cur_t += 1;
        }
        return cur_s == s.size();
    }
};