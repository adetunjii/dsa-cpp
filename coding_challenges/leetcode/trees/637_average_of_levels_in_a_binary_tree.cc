#include "treenode.h"
#include <queue>
#include <ranges>
#include <vector>

std::vector<double> averageOfLevels(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }

    queue<int> q;
    vector<double> res;

    while (!q.empty()) {
        int levelSize = q.size();

        int levelSum = 0;

        for (int i : std::views::iota(0, levelSize)) {
            int top = q.front();
            q.pop();

            levelSum += top;
        }

        res.push_back(levelSum / levelSize);
    }

    return res;
}