#include <stack>
#include <vector>
#include "treenode.h"

void dfs(TreeNode* root, std::vector<int>& nums) {
    if (root == nullptr) return;

    dfs(root->left, nums);
    if (root->left == nullptr && root->right == nullptr) {
        nums.push_back(root->val);
    }
    dfs(root->right, nums);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    std::stack<int> st;

    std::vector<int> nums1;
    std::vector<int> nums2;

    dfs(root1, nums1);
    dfs(root2, nums2);

    if (nums1.size() != nums2.size()) return false;

    return equal(nums1.begin(), nums1.end(), nums2.begin());
}