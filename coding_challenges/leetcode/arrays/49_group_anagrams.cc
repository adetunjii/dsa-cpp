#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    string sortWord(string word) {
        string sortedWord;
        int bucket[26] = {0};

        for (const char& c : word) {
            bucket[c - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++) { 
            int count = bucket[i];
            while(count > 0) {
                sortedWord += (char)(i + 'a');
                count -= 1;
            }
        }
        return sortedWord;
    }

    vector<vector<string>> groupAnagram(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;

        for (const auto& str : strs) {
            auto sortedWord = sortWord(str);
            m[sortedWord].push_back(str);
        }

        for (const auto& [_, val] : m) {
            res.push_back(val);
        }
        return res;
    }
};