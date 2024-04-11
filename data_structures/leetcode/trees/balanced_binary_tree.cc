#include <iostream>
#include "treenode.h"

using namespace std;

class SolutionNaive {
public:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        return max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int left = height(root->left);
        int right = height(root->right);

        return abs(left-right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
     }
};

class Solution {
public:
    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = height(node->left);
        if (left == -1) { return -1; }

        int right = height(node->right);
        if (right == - 1) {return -1;}

        if(abs(left-right) > 1) {
            return -1;
        }

        return abs(left - right) <= 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (height(root) == -1) { return false;}
        return true;
    }

};

