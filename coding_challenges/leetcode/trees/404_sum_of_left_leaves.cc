#include <ranges>
#include <vector>
#include "treenode.h"

void preorder(TreeNode* root, std::vector<int>& res) {
    if (root == nullptr) {
        res.push_back(0);
    } else {
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }


}

int sumOfLeftLeaves(TreeNode* root) {
   int sum = 0;

    std::vector<int> res;
    preorder(root, res);
    int N = res.size();
    for (int i : std::views::iota(0, N)) {
        if (i > -1001 && (i % 2) == 1) {
            sum += res[i];
        }
    }

    return sum;
}