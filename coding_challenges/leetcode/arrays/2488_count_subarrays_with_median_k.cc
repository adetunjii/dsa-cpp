#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int countSubarrays(vector<int>& nums, int k) {
            int N = nums.size();
            int idx = find(nums.begin(), nums.end(), k) - nums.begin(); // find the index of k (no duplicates, question says distinct elements)
            int cnt[N*2];   // initialize an array of size 2n to map from -n to n since in the worst case where all elements are less than k, we will have -n    
                            // or if all the elements are greater than k then we'll have N elements. 
                            // In summary, we create an array of size 2N to map the array to (-n, n) space. for ex: if N = 4, and x = -2 to map it into the array, -2 + 4 = 2
            memset(cnt, 0, sizeof(cnt));
            int res = 1, prefix = 0;

            for (int i = idx + 1; i < N; i++) {
                prefix += nums[i] > k ? 1 : -1;
                if (prefix >= 0 && prefix <= 1) { // find valid subarrays on the RHS
                    res += 1;
                }
                cnt[prefix + N] += 1;
            }

            prefix = 0;
            for (int j = idx -1; j >= 0; j--) {
                prefix += nums[j] > k ? 1 : -1;
                if (prefix >= 0 && prefix <= 1) { // find valid subarrays on the LHS
                    res += 1;
                }
                res += cnt[-prefix+N] + cnt[-prefix+N+1]; // find subarrays that overlap on the LHS and RHS
            }
            return res;
        }
    };