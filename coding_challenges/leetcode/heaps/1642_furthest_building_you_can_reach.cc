#include <vector>
#include <queue>
#include <ranges>

int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        int N = heights.size();

        auto cmp = [&](int a, int b) {
            return a > b;
        };

        std::priority_queue<int> pq;

        int count = 0;

        for(auto i : std::views::iota(0, N-1)) {
            if (heights[i] >= heights[i+1]) {
                count += 1;
                continue;
            }

            if (heights[i] < heights[i+1]) {
                int diff = heights[i+1] - heights[i];
                bricks -= diff;
                count += 1;
                pq.push(diff);
            }

            if (bricks < 0) {
                bricks += pq.top();
                pq.pop();
                ladders -= 1;
            }

            if (ladders < 0) {
                count -= 1;
                break;
            }
        }

        return count;
}