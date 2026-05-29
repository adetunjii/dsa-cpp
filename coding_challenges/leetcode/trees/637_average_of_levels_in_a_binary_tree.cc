#include "treenode.h"
#include <queue>
#include <ranges>
#include <vector>

std::vector<double> averageOfLevels(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }

    std::queue<TreeNode*> q;
    std::vector<double> res;

    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        double levelSum = 0;

        for (int i : std::views::iota(0, levelSize)) {
            auto top = q.front();
            q.pop();

            levelSum += top->val;

            if (top->left != nullptr)
                q.push(top->left);
            if (top->right != nullptr)
                q.push(top->right);
        }

        res.push_back(levelSum / levelSize);
    }

    return res;
}