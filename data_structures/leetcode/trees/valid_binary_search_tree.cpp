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
};


int main() {
    TreeNode* left = new TreeNode(4);
    TreeNode* rl = new TreeNode(3);
    TreeNode* rr = new TreeNode(7);

    TreeNode* right = new TreeNode(6, rl, rr);

    TreeNode* root = new TreeNode(5, left, right);

    Solution sol;
    cout << sol.isValidBSTRecursive(root) << endl;

    free(left);
    free(rl);
    free(rr);
    free(right);
    free(root);

    return 0;
}