#include <iostream>
#include <queue>
#include "treenode.h"

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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        long maxWidth = 1;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 1});

        while(!q.empty()) {
            long startPos = q.front().second; // leftmost index at each level
            long endPos = q.back().second;  // rightmost index at each level

            maxWidth = max(endPos - startPos + 1, maxWidth);

            int currentQueueSize = q.size();
            
            for(int i = 0; i < currentQueueSize; i++) {
                TreeNode* front = q.front().first;
                int pos = q.front().second;    // index of the current node. 
                                               // this is important to calculate the index of its left and right child nodes
                q.pop();

                if (front->left != nullptr) q.push({front->left, 2L * pos});
                if (front->right != nullptr) q.push({front->right, 2L * pos + 1});
            }
        }

        return static_cast<int>(maxWidth);
    }
};
