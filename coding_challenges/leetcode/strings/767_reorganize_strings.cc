#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26);
        int maxCount = 0;
        char maxChar;

        for (char c : s) {
            count[c-'a'] += 1;
            if (count[c-'a'] > maxCount) {
                maxCount = count[c-'a'];
                maxChar = c;
            }
        }

        int total = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (c != maxChar) total += count[c-'a'];
        }

        if (maxCount - total > 1) return "";
        
        const int N = s.size();
        string res(N, ' ');
        int idx = 0;
        while(maxCount > 0) { 
            res[idx] = maxChar;
            count[maxChar-'a'] -= 1;
            idx += 2;
            maxCount -= 1;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            while (count[c-'a'] > 0) {
                if (idx >= N) {
                    idx = 1;
                }
                res[idx] = c;
                idx += 2;
                count[c-'a'] -= 1;
            }
        }
        return res;
    }
};