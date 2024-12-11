#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N, 1);
        
        int x = 1;
        for (int i = 1; i < nums.size(); i++) {
            res[i] = x * nums[i-1];
            x = res[i];
        }

        int prev = 1;
        for (int j = N - 1; j >= 0; j--) {
            res[j] *= prev;
            prev *= nums[j];
        }

        return res;
    }
};