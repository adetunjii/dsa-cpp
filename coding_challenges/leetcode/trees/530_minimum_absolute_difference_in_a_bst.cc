#include "treenode.h"
#include <algorithm>
#include <vector>

void minimumDiff(TreeNode* root, std::vector<int>& nums) {
    if (root == nullptr) {
        return;
    }

    minimumDiff(root->left, nums);
    nums.push_back(root->val);
    minimumDiff(root->right, nums);
}

int getMinimumDifference(TreeNode* root) {
    vector<int> nums;

    minimumDiff(root, nums);
    int minDiff = 1000001;
    for (int i = 0; i < nums.size() - 1; i++) {
        minDiff = std::min(minDiff, std::abs(nums[i] - nums[i + 1]));
    }

    return minDiff;
}