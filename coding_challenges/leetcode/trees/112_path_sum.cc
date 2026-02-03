#include <vector>
#include "treenode.h"

namespace tree {
    bool hasPathSum(TreeNode* node, int targetSum) {
         if (node == nullptr) {
            return false;
        }

        if (node->left == nullptr && node->right == nullptr) { // leaf node;
            return targetSum - node->val == 0;
        }

        return hasPathSum(node->left, targetSum) || hasPathSum(node->right, targetSum);
    }
}