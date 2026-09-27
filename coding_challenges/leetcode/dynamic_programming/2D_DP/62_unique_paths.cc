#include <vector>

namespace dp {
int uniquePaths(int m, int n) {
    if (m == 0 && n == 0) return 0;

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j];
        }
    }

    return dp[m-1][n-1];
}

int uniquePathsOptimized(int m, int n) {
    if (m == 0 && n == 0) return 0;

    std::vector<int> dp(n, 1);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j-1];
        }
    }

    return dp[n-1];
}
}