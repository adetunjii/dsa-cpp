#include <queue>

namespace queue {
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int N = tickets.size();
        if (N == 0) return 0;

        std::queue<std::pair<int, int>> q;
        int count = 0;
        for (size_t i : std::views::iota(0, N)) {
            q.push({tickets[i], i});
        }

        while(!q.empty()) {
            int remTickets = q.front().first - 1;
            count += 1;

            if (remTickets == 0 && q.front().second == k) {
                return count;
            } else if (remTickets == 0 && q.front().second != k) {
                q.pop();
            } else{
                q.push({remTickets, q.front().second});
                q.pop();
            }
        }

        return count;
    }
}