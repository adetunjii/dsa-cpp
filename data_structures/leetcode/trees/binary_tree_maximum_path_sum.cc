#include <iostream>
#include "treenode.h"

using namespace std;

class Solution {
public:
    int maxPath(TreeNode* node, int& m) {
        if (node == nullptr) return 0;

        int left = max(0, maxPath(node->left, m));
        int right = max(0, maxPath(node->right, m));

        m = max(m, left + right + node->val);
        return max(left, right) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        if (root == nullptr) return 0;

        maxPath(root, maximum);
        return maximum;
    }
};