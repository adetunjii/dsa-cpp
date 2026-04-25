#include "treenode.h"
#include <ranges>
#include <vector>

int sumOfLeftNodes(TreeNode* root, bool isLeft) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return isLeft ? root->val : 0;
    }

    return sumOfLeftNodes(root->left, true) + sumOfLeftNodes(root->right, false);
}

int sumOfLeftLeaves(TreeNode* root) {
    return sumOfLeftNodes(root, true) + sumOfLeftNodes(root, false);
}