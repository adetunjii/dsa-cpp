#include <vector>
#include <ranges>
#include <queue>

typedef std::pair<long, long> P;
std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks) {
    int N = servers.size();
    int M = tasks.size();

    std::priority_queue<P, std::vector<P>, std::greater<>> pool;
    std::priority_queue<P, std::vector<P>, std::greater<>> runqueue;

    for (int i : std::views::iota(0, N)) pool.emplace(servers[i], i);

    std::vector<int> res;
    res.reserve(M);

    long running_time = 0;

    for (int i : std::views::iota(0, M)) {
        running_time = std::max(static_cast<long>(i), running_time);

        if (pool.empty() && running_time < runqueue.top().first) {
            running_time = runqueue.top().first;
        }

        while (!runqueue.empty() && running_time >= runqueue.top().first) {
            int server_idx = runqueue.top().second;
            pool.emplace(servers[server_idx], server_idx);
            runqueue.pop();
        }

        int server_idx = pool.top().second;
        runqueue.emplace(running_time + tasks[i], server_idx);
        res.push_back(server_idx);
        pool.pop();
    }
    
    return res;
}