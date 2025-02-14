#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        long long countSubarraysBrute(vector<int>& nums, long long k) {
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

        long long countSubarrays(vector<int>& nums, long long k) {
            int N = nums.size(), l = 0;
            long long result = 0, sum = 0;

            for (int r = 0; r < N; r++) {
                sum += nums[r];
                while (sum * (r-l+1) >= k) {
                    sum -= nums[l]
                    l += 1;
                }
                // the number of subarrays we can form from the current subarray => count + validWindowLength;
                res += r - l +1
            }
            return result;
        }
    };