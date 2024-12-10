#include <iostream>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto str : strs) {
            encoded += str;
            encoded += '\n';
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;

        string temp = "";
        for (auto c : s) {
            if (c == '\n') {
                res.push_back(temp);
                temp = "";
                continue;
            }
            temp += c;
        }

        return res;
    }
};
