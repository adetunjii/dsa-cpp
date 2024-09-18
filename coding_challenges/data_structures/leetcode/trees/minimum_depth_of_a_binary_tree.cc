#include <iostream>
#include "treenode.h"

class Solution {
private:
    int depth(TreeNode* node) {
        if(node == nullptr) return 0;

        // leaf node
        if (node->left == nullptr && node->right == nullptr) return 1;

        // has only left
        if (node->left && node->right == nullptr) {
            return depth(node->left) + 1;
        } else if (node->right && node->left == nullptr) { // has only right
            return depth(node->right) + 1;
        }

        return min(depth(node->left), depth(node->right)) + 1;
    }
public:
    int minDepth(TreeNode* root) {
        return depth(root);
    }
};