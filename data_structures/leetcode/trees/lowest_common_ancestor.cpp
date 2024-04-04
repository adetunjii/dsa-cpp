#include <iostream>
#include "treenode.h"

// this solution takes an iterative approach and takes an advantage of the properties of a
// binary tree.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != nullptr) {
            if(p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }

        return nullptr;
    }
};