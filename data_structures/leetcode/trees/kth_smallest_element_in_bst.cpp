#include <iostream>
#include "treenode.h"

using namespace std;

class Solution {
public:
    vector<int> temp;

    void inorder(TreeNode* node) {
        if (node == nullptr) return;

        inorder(node->left);
        temp.push_back(node->val);
        inorder(node->right);
    }

    int kthSmallestElement(TreeNode* root, int k) {
        if (root == nullptr) return 0;
        inorder(root);
        return temp[k-1];
    }
};