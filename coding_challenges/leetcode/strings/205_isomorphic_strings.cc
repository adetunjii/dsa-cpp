#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

       unordered_map<char, int> ms;
       unordered_map<char, int> mt;

        for (int i = 0; i < s.size(); i++) {
            ms[s[i]] += 1;
            mt[t[i]] += 1;
        }

        for (int i = 0; i < s.size(); i++) {
            if (mt[t[i]] != ms[s[i]]) return false;
        }

        return true;
    }
};