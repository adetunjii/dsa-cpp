#include <vector>
#include "treenode.h"

void inorder(TreeNode* root, std::vector<int>& nums) {
    if (root == nullptr) return;

    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> nums;
    inorder(root, nums);
    return nums;
}