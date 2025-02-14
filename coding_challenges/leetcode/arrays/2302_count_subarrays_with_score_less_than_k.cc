#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            int N = nums.size();
            long long result = 0;
    
            for (int i = 0; i < N; i++) {
                long long score = 0;
                for (int j = i; j < N; j++) {
                    score += nums[j];
                    if (score * (j - i + 1) < k) result += 1;
                    else break;
                }
            }
            return result;
        }
    };