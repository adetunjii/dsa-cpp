#include <iostream>
#include <span>
#include <vector>
#include "treenode.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int findMaxIdx(span<int> nums) {
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[m]) {
                m = i;
            }
        }
        return m;
    }

    TreeNode* constructTree(span<int> nums) {
        if (nums.empty()) return nullptr;

        int maxIdx = findMaxIdx(nums);

        span<int> left(nums.begin(), maxIdx);
        span<int> right(nums.begin() + maxIdx + 1, nums.end());

        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = constructTree(left);
        root->right = constructTree(right);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        span<int> s(nums);
        return constructTree(s);
    }
};
