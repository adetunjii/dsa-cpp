#include <vector>
#include <ranges>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    int M = obstacleGrid.size();
    int N = obstacleGrid[0].size();

    if (M == 0 & N == 0) return 0;

    std::vector<int> dp(N, 1);
    for (int j : std::views::iota(0, N)) {
        if (obstacleGrid[0][j] == 1 || (j > 0 && dp[j-1] == 0)) {
            dp[j] = 0;
        }
    }

    for (int i : std::views::iota(1, M)) {
        if (obstacleGrid[i][0] == 1) dp[0] = 0;
        for (int j : std::views::iota(1, N)) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
            } else {
                dp[j] += dp[j-1];
            }
        }
    }

    return dp[N-1];
}