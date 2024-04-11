#include <iostream>
#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
public:
    int height(TreeNode* node, int& maxDiameter) {
        if (node == 0) return 0;

        int left = height(node->left, maxDiameter);
        int right = height(node->right, maxDiameter);

        maxDiameter = max(maxDiameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfABinaryTree(TreeNode* root) {
        int max = 0;
        if (root == nullptr) return 0;

        height(root, max);
        return max;
    }  
};