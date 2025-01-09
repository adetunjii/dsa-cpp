#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char, int> mm;

        for (int i = 0; i < magazine.size(); i++) {
            mm[magazine[i]] += 1;
        } 
        
        for (char c : ransomNote) {
            if (mm[c] > 0) {
                mm[c] -= 1;
            } else {
                return false;
            }
        }
     
        return true;
    }
};