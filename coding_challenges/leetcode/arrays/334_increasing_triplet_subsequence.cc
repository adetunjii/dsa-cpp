#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int N = nums.size();

        int first = nums[0], second = INT_MAX;

        for (int num : nums) {
            if (num > second) return true;

            if (num <= first) {
                first = num;
            } else if (num > first && num < second) {
                second = num;
            } 
        }
        return false;
    }
};