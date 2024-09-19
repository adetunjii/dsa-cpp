#include <iostream>
#include "treenode.h"

using namespace std;

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return res;

        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);

        return res;
    }
};