#include <vector>
#include <queue>
#include <ranges>

typedef std::pair<int, int> P;

std::vector<int> getOrder(std::vector<std::vector<int>>& tasks) {
    int N = tasks.size();

    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

    std::vector<int> res;
    res.reserve(N);
    int running_time = 0, i = 0;

    for (int i : std::views::iota(0, N)) tasks[i].push_back(i);

    std::sort(tasks.begin(), tasks.end());

    while (i < N || pq.size() > 0) {
        if (pq.empty()) {
            running_time = std::max(running_time, tasks[i][0]);
        }

        while (i < N || running_time >= tasks[i][0]) {
            pq.emplace(tasks[i][1], tasks[i][2]);
            i += 1;
        }

        running_time += (pq.top().first);
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}