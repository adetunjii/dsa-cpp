#include <iostream>
#include "treenode.h"
using namespace std;

class Solution{
    TreeNode* searchBinaryTree(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;

        while(root != nullptr) {
            if (val < root->val) {
                root = root->left;
            } else if (val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};