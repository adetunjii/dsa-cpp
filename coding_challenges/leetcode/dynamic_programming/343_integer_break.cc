#include <algorithm>
#include <vector>

namespace dp {
int integerBreak(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = std::max(dp[i], std::max(j * (i - j), j * dp[i - j]));
        }
    }

    return dp[n];
}
} // namespace dp