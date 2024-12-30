#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int N = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < N; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int current = nums[i];
            int start = i + 1, end = nums.size() - 1;

            while(start < end) {
                int sum = current + nums[start] + nums[end];

                if (sum > 0) {
                    end -= 1;
                } else if (sum < 0) {
                    start += 1;
                } else {
                    res.push_back({current, nums[start], nums[end]});
                    start += 1;
                    end -= 1;

                    // this is important since the array is already sorted and the positions
                    // of start and end have changed:
                    // There are one of two situations that we can encounter:
                    // 1. The end has moved left and nums[end] is a smaller value (since the array is sorted).
                    //    Since we already know the previous start value, then we can assume that the sum would be smaller.
                    //
                    // 2. The start value and end values are the same after shifting left and right respectively. i.e we 
                    //    get duplicate triplet values. We can choose to shift both pointers in this case, but since we are
                    //    already checking to see that start is not the same as before, we avoid duplicates.
                    while (start < end && nums[start] == nums[start-1]) {
                        start += 1;
                    }
                }
            }
        }

        return res;
    }
};