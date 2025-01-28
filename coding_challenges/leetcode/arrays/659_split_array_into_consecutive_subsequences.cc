#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, tails;

        for (int num : nums) {
            count[num] += 1;
        }

        for (int num : nums) {
            if (count[num] == 0) continue;
            count[num] -= 1;
            if (tails[num-1] > 0) {
                tails[num-1] -= 1;
                tails[num] += 1;
            } else {
                if (count[num+1] > 0 && count[num+2] > 0) {
                    count[num+1] -= 1;
                    count[num+2] -= 1;
                    tails[num-1] -= 1;
                    tails[num+2] += 1;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};