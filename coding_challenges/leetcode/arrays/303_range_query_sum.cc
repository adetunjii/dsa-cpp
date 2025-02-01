#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int N = nums.size();
        prefix = vector<int>(N, 0);
        prefix[0] = nums[0];

        for (int i = 1; i < N; i++) {
            prefix[i] = prefix[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int i = 0, cur = prefix[right];
        if (left > 0) {
            return cur - prefix[left-1];
        }
        return cur;
    }
};