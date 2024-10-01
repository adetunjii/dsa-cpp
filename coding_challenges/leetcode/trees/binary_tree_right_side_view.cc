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
            auto back = q.back();
            size_t currentQSize = q.size();
            res.push_back(back->val);


            // clear the current nodes in the queue and add the nodes of the next level in the tree. 
            for (size_t i = 0; i < currentQSize; i++) {
                auto front = q.front();
                q.pop();

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }

        return res;
    }
};
