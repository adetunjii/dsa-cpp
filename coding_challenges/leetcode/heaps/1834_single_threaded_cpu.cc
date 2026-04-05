#include <vector>
#include <ranges>
#include <queue>

typedef std::pair<int, int> P;

std::vector<int> getOrder(std::vector<std::vector<int>>& tasks) {
    int N = tasks.size();

    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

    std::vector<int> res;
    res.reserve(N);

    long running_time = 0;
    int idx = 0;

    for (int i : std::views::iota(0, N)) tasks[i].push_back(i); // each item in the tasks array now has [enqueue_time, processing_time, task_idx]

    std::sort(tasks.begin(), tasks.end());

    while (idx < N || pq.size() > 0) {
        if (pq.empty() && tasks[idx][0] < running_time) {
            running_time = (long)tasks[idx][0];
        }

        while (idx < N && running_time >= tasks[idx][0]) {
            pq.emplace(tasks[idx][1], tasks[idx][2]);
            idx += 1;
        }

        running_time += pq.top().first;
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}
