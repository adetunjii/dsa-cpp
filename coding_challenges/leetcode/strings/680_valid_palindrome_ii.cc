#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string& s) {
        int l = 0, r = s.size()-1;

        auto isPalindrome = [&s](int i, int j) {
            while (i <= j) {
                if (s[i] != s[j]) return false;
                i += 1;
                j -= 1;
            }
            return true;
        };

        while(l <= r) {
            if (s[l] != s[r]) {
                return isPalindrome(l+1, r) || isPalindrome(l, r-1);
            }

            l += 1;
            r -= 1;
        }
        return true;
    }
};