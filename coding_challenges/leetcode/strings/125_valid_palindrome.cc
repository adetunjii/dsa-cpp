#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l <= r) {
            if (!isalnum(s[l])){
                l += 1;
            } else if (!isalnum(s[r])) {
                r -= 1;
                continue;
            } else if (tolower(s[l]) != tolower(s[r])) {
                return false;
            } else {
                l += 1;
                r -= 1;
            }
        }
        return true;
    }
};