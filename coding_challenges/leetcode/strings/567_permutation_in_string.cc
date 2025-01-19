#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        vector<int> A(26, 0), B(26, 0);
        auto isEqual = [&]() {
            for (int i = 0; i < 26; i++) {
                if (A[i] != B[i]) return false;
            }
            return true;
        };

        for (char c : s1) {
            A[c-'a'] += 1;
        }

        for (int i = 0; i < s1.size(); i++) {
            B[s2[i]-'a'] += 1;
        }

        if (isEqual()) return true;

        for (int r = s1.size(); r < s2.size(); r++) {
            B[s2[r]-'a'] += 1;
            B[s2[r-s1.size()] - 'a'] -= 1;

            if (isEqual()) return true;
        }
        return false;
    }
};