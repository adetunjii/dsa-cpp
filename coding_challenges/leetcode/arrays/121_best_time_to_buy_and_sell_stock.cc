#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;
        int prev = prices[0];
        int i = 1, N = prices.size();
        while (i < N) {
            if (prices[i] < prev) {
                prev = prices[i];
            } else {
                profit = max(profit, prices[i]-prev);
            }
            i += 1;
        }

        return profit;
    }
};