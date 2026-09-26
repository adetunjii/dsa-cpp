#include <algorithm>
#include <ranges>
#include <vector>

namespace dp {
int maxProfit(std::vector<int>& prices) {
    if (prices.empty())
        return 0;

    int N = prices.size();
    int holding = -prices[0], rest = 0, sold = 0;

    for (int i : std::views::iota(1, N)) {
        int temp = holding;
        holding = std::max(holding, rest - prices[i]);
        rest = std::max(sold, rest);
        sold = temp + prices[i];
    }

    return std::max(rest, sold);
}
} // namespace dp