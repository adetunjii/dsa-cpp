#include <vector>
#include <ranges>
#include <algorithm>

int minPathSum(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::vector<int> dp(n, INT_MAX);
    dp[0] = grid[0][0];

    for (int i : std::views::iota(1, n)) {
        dp[i] = dp[i-1] + grid[0][i];
    }

    for (int i : std::views::iota(1, m)) {
        dp[0] += grid[i][0];
        for (int j : std::views::iota(1, n)) {
            dp[j] = std::min(dp[j] + grid[i][j], dp[j-1] + grid[i][j]);
        }
    }

    return dp[n-1];
}