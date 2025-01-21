#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0;
        vector<int> arr(26);

        int l = 0, maxFreq = 0;

        for (int r = 0; r < s.size(); r++) {
            arr[s[r]-'A'] += 1;
            maxFreq = max(maxFreq, arr[s[r]-'A']);

            if (r-l+1 - maxFreq > k) {
                arr[s[l]-'A'] -= 1;
                l += 1;
            }
            longest = max(longest, r-l+1);
        }
        return longest;
    }
};