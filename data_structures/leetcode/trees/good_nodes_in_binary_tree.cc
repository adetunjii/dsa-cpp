#include <iostream>
#include "treenode.h"

using namespace std;

class Solution {
public:
    int count = 1;

    void isGood(TreeNode* node, int max) {
        if (!node) return;

        if (node->val >= max) {
            count += 1;
            max = node->val;
        }

        isGood(node->left, max);
        isGood(node->right, max);
    }


    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        isGood(root->left, root->val);
        isGood(root->right, root->val);
        return count;
    }
};