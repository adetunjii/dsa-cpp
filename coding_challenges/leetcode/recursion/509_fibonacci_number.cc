#include <iostream>
#include <numeric>
#include <ranges>

class Solution {
public:
    int fibonacci(int n) { 
        return getFib(n, 0, 1); 
    }

    int fib_dp(int N) {
        std::vector<int> dp(N+1, 0);

        if(N == 0) return 0;

        for (int i : std::views::iota(2, N+1)) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[N];
    }

    // using tail recursion
    int getFib(int n, int a, int b) {
        if (n == 0) return a;
        if (n == 1) return b;

        return getFib(n-1, b, a+b);
    }
};