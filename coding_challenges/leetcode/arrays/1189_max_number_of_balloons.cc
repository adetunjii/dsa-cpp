#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
       // store the characters and their counts in a hashmap
       // loop through the hashmap to form the word balloon from the characters
       // and use a while loop so that we can exhaust all the characters in the hashmap
       // also need to delete a character whose count == 0

        unordered_map<char, int> m;
        int res = 0;

       for (int i = 0; i < text.length(); i++) {
        m[text[i]] += 1;
       }

        while (!m.empty()) {
            if (m['b'] >= 1 && m['a'] >= 1 && m['l'] >= 2 && m['o'] >= 2 && m['n'] >= 1) {
                res += 1;
                
                m['b'] -= 1;
                m['a'] -= 1;
                m['l'] -= 2;
                m['o'] -= 2;
                m['n'] -= 1;
            } else {
                break;
            }
        }

       return res;
    }
};