#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }

        vector<int> indexes, sc(26, 0), pc(26, 0);
        auto isEqual = [&]() -> bool {
            for (int i = 0; i < 26; i++) {
                if (sc[i] != pc[i]) {
                    return false;
                }
            }
            return true;
        };

        for (int i = 0; i < p.size(); i++) {
            pc[p[i] - 'a'] += 1;
            sc[s[i] - 'a'] += 1;
        }

        if (isEqual()) {
            indexes.push_back(0);
        }

        int r = p.size();
        while(r < s.size()) {
            sc[s[r] - 'a'] += 1;
            sc[s[r-p.size()] - 'a'] -= 1;

            if (isEqual()) {
                indexes.push_back(r-p.size()+1); // +1 because we've already deleted the character at `r-p.size()`. So `r-p.size()+1` gives the correct left pointer.
            }
            r += 1;
        }
        return indexes;
    }
};