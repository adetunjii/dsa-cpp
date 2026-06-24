#include <iostream>
#include <string>
#include <vector>

std::string encode(std::vector<std::string>& strs) {
    std::string encoded = "";
    for (auto str : strs) {
        encoded += str;
        encoded += '\n';
    }
    return encoded;
}

std::vector<std::string> decode(std::string s) {
    std::vector<std::string> res;

    std::string temp = "";
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
