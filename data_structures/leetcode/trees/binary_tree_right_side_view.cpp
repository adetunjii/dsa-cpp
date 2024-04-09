#include <iostream>
#include <vector>
#include <queue>
#include "treenode.h"

using namespace std;

class Solution {
public: 
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> temp;
            for(int i = 0; i < q.size(); i++) {
                TreeNode* front = q.front();
                q.pop();

                temp.push_back(front->val);

                if (front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            } 

            res.push_back(temp.back());
        }

        return res;
    }
};
