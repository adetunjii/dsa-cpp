#include <iostream>
#include <map>
#include <string>

bool canConstruct(std::string ransomNote, std::string magazine) {
    std::map<char, int> mm;

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