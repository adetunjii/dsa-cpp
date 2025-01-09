#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int c = 0;

            while (c < strs[i].size() && strs[i][c] == prefix[c]) {
                c += 1;
            }

            prefix = prefix.substr(0, c);
        }
        return prefix;
    }
};