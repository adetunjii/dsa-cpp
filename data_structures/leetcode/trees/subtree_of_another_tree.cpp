#include <iostream>
#include "treenode.h"

using namespace std;

class Solution {
public:
  bool checkNodes(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) return true;
    if (!root || !false) return false;

    if (root->val == subRoot->val) {
        return checkNodes(root->left, subRoot->left) && checkNodes(root->right, subRoot->right);
    }

    return false;
  }

  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) return false;
    if(subRoot == nullptr) return true;

    if (checkNodes(root, subRoot)) return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};