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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();

                temp.push_back(top->val);

                if (top->left != nullptr) q.push(top->left);
                if (top->right != nullptr) q.push(top->right);
                
            }

            res.push_back(temp);
        }

        return res;
    }
};


using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        res.push_back({root->val});

        while(!q.empty()) {
            vector<int> temp;
            for (int i = 0; i < q.size(); i++) {
                TreeNode* top = q.front();
                q.pop();

                temp.push_back(top->val);
            
                if (top->left != nullptr) q.push(top->left);
                if (top->right != nullptr) q.push(top->right);
            }

            res.push_back(temp);
        }

        return res;
    }
};