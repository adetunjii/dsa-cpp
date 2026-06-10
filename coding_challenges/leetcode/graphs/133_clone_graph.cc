#include "node.h"
#include <queue>
#include <unordered_map>
#include <vector>

Node* cloneGraph(Node* node) {
    if (node == nullptr)
        return nullptr;

    std::unordered_map<Node*, Node*> map;
    auto start = node;
    std::queue<Node*> q;
    q.push(start);

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        Node* clone;
        if (map.find(front) == map.end()) {
            clone = new Node(front->val);
            map[front] = clone;
        } else {
            clone = map[front];
        }

        for (auto neighbor : front->neighbors) {
            if (map.find(neighbor) == map.end()) {
                map[neighbor] = new Node(neighbor->val);
                q.push(neighbor);
            }

            clone->neighbors.push_back(map[neighbor]);
        }

        return map[node];
    }
}