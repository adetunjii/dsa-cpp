#include <iostream>
#include <vector>
#include <stack>
#include "treenode.h"

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool res = true;
        if (root == nullptr) return true;

        stack<TreeNode*> st;
        vector<int> temp;

        while(root != nullptr || !st.empty()) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode* top = st.top();
                st.pop();

                temp.push_back(top->val);
                root = top->right;
            }
        }

        for (int i = 0; i < temp.size()-1 - 1; i++) {
            if (temp[i] > temp[i-1]) return false;
        }
        
        return res;
    }
    
    bool isBST(TreeNode* node, long long min, long long max) {
        if (node == nullptr) return true;

        if (node->val > min && node->val < max) {
            bool left = isBST(node->left, min, node->val);
            bool right = isBST(node->right, node->val, max);

            return left && right;
        }

        return false;
    }

    bool isValidBSTRecursive(TreeNode* root) {
        if (root == nullptr) return true;
        return isBST(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }

    bool inorder(TreeNode* node, long& prev) {
        if (node == nullptr) return true;

        if (!inorder(node->left, prev)) return false;
        if (node->val <= prev) return false;
        prev = node->val;
        if (!inorder(node->right, prev)) return false;

        return true;
    }

    bool isValidBSTInorder(TreeNode* root) {
        long prev = std::numeric_limits<long>::min();
        return inorder(root, prev);
    }
};


