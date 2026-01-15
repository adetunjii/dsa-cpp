#include <vector>
#include <ranges>

namespace dp {
    int maxProfitII(std::vector<int>& prices) {
        int N = prices.size();
        if (N < 2) return 0;

        int dp = 0;
        
        for (int i : std::views::iota(1, N)) {
            dp = std::max(dp, prices[i] - prices[i-1] + dp);
        }

        return dp;
    }
}