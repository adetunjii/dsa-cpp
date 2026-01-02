#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int N = nums.size(), slot = 1;

      for (int i = 0; i < N; i++) {
        if (nums[i] > nums[slot - 1]) {
            nums[slot] = nums[i];
            slot += 1;
        }
      }
      return slot;
    }
};
