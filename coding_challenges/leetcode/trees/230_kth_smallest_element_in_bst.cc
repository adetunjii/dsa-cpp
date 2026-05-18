#include <iostream>
#include "treenode.h"

using namespace std;

class Solution {
public:
    void inorder(TreeNode* node, vector<int>& nums) {
        if (node == nullptr) return;

        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }

    int kthSmallestElement(TreeNode* root, int k) {
        vector<int> nums;
        if (root == nullptr) return 0;
        inorder(root, nums);
        return nums[k-1];
    }
};