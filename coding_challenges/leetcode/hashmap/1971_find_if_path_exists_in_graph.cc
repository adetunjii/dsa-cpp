#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

namespace graph {
bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    std::unordered_map<int, std::vector<int>> adjList;
    for (auto& edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    std::set<int> visited;
    visited.insert(source);

    std::queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == destination) {
            return true;
        }

        for (int neighbor : adjList[node]) {
            if (visited.count(neighbor) == 0) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    return false;
}
} // namespace graph