#include <queue>
#include <unordered_map>
#include <vector>

Node* cloneGraph(Node* node) {
    std::unordered_map<Node*, Node*> map;
    Node* start = node;
    std::queue<Node*> q;
    q.push(start);

    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        if (map.find(top) == map.end()) {
            auto val = top->val;
            map[top] = new Node(val);
        }

        for (auto child : top->neighbors) {
            q.push(child);
            map[top]->neighbors.push_back(child);
        }
    }

    return map[node];
}