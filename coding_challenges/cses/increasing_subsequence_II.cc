#include <iostream>
#include <vector>
#include <numeric>

#define ll long long int

namespace cses {
    ll increasingSubsequenceII(std::vector<int>& nums) {
        int N = nums.size();

        ll M = 10e9 + 7;

        // dp table holds, number of subsequences starting and ending at nums[i];
        std::vector<ll> dp(N, 1);

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = (dp[i] + dp[j]) % M;
                }
            }
        }

        return std::accumulate(dp.begin(), dp.end(), 0);
    }
}