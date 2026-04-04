#include <vector>
#include <queue>
#include <ranges>

std::vector<int> getOrder(std::vector<std::vector<int>>& tasks) {
    int N = tasks.size();

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    for (int i : std::views::iota(0, N)) tasks[i].push_back(i);
    
    std::sort(tasks.begin(), tasks.end());
    int running_time = 0;
    
    int i = 0;

    std::vector<int> res;

    while (i < N || pq.size()) {
        if (pq.empty()) {
            running_time = std::max(running_time, tasks[i][0]);
        }

        while (i < N && running_time >= tasks[i][0]) {
            pq.emplace(tasks[i][1], tasks[i][2]);
            i += 1;
        }

        auto [proc, idx] = pq.top();
        pq.pop();
        running_time += proc;
        res.push_back(idx);
    }

    return res;
}