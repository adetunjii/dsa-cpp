#include <iostream>
#include <vector>
#include <ranges>

int numSquares(int N) {
    std::vector<int> squares;

    int i = 1;
    while (i * i <= N) {
        squares.push_back(i * i);
        i += 1;
    }
    int squaresLen = squares.size();
    
    std::vector<int> dp(N+1, N+1);
    dp[0] = 0;

    for (int i : std::views::iota(1, squaresLen+1)) {
        for (int c : std::views::iota(1, N + 1)) {
            if (squares[i-1] <= c)
                dp[c] = std::min(dp[c], dp[c-squares[i-1]] + 1);
        }
    }

    return dp[N];
}