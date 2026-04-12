#include <algorithm>
#include <queue>
#include <vector>

int lastStoneWeight(std::vector<int>& stones) {
    int N = stones.size();
    if (N == 1)
        return stones[0];

    std::priority_queue<int> pq(stones.begin(), stones.end());

    while (pq.size() >= 2) {
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();

        if (abs(A - B) > 0) {
            pq.push(abs(A - B));
        }
    }

    if (!pq.empty()) {
        return pq.top();
    }

    return 0;
}