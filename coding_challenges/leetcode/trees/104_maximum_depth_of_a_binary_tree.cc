#include <iostream>
#include "treenode.h"

namespace trees {
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int countLeft = maxDepth(root->left);
        int countRight = maxDepth(root->right);

        return std::max(countLeft, countRight) + 1;
    }
}