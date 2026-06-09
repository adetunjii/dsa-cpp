#include <iostream>
#include <utility>
#include <functional>
#include "treenode.h"


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
    std::pair<bool, int> recurse(TreeNode* node) {
        if (node == nullptr) return make_pair(true, 0);

        auto left = recurse(node->left);
        auto right = recurse(node->right);

        int maxHeight = max(left.second, right.second);
        bool isValid = abs(left.second-right.second) <= 1 && left.first && right.first; // recursive case;

        return make_pair(isValid, maxHeight);
    } 

    bool isBalanced(TreeNode* root) {   
        return recurse(root).first;
    }
};

