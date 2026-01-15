#include <vector>
#include <ranges>

namespace dp {
    int maxProfit(std::vector<int>& prices) {
        int N = prices.size();
        if (N < 2) return 0;

        int dp = 0, currentMin = prices[0];
        
        for (int i : std::views::iota(1, N)) {
            if (prices[i] < currentMin) {
                currentMin = prices[i];
            } else {
                dp = std::max(dp, prices[i] - currentMin);
            }
        }

        return dp;
    }
}