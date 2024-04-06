#include <iostream>
#include <queue>
#include "treenode.h"

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