#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarrays(vector<int>& nums) {
        long long count = 0, lastZeroCount = 0;
        for (int num : nums) {
            count += ++lastZeroCount;
        } else {
            lastZeroCount = 0
        }
    }

    return count;
}