#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slot = 1;
        if (nums.size() == 1) return 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[slot] = nums[i];
                slot += 1;
            }
        }
        return slot;
    }
};