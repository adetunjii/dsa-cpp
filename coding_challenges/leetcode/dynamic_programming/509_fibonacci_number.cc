#include <iostream>
#include <vector>
#include <ranges>

namespace dp {
int fib(int n);

int fib(int N) {
    if (N <= 1) return N;

    std::vector<int> dp(N+1, 0);
    dp[0] = 0, dp[1] = 1;

    for(int i : std::views::iota(2, N + 1)) {
        dp[i] = dp[i - 1] + dp[i-2];
    }

    return dp[N];
}
}
