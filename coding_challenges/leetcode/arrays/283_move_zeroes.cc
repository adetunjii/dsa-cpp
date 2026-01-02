#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int nonZeroIdx = 0;

       for(int i = 0; i < nums.size(); i++) {
         if (nums[i] != 0){
           int temp = nums[nonZeroIdx];
           nums[nonZeroIdx] = nums[i];
           nums[i] = temp;
         }
       } 
    }
};
