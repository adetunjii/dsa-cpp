#include "treenode.h"
#include <algorithm>
#include <limits.h>

TreeNode* first = nullptr;
TreeNode* second = nullptr;
TreeNode node = TreeNode(INT_MIN);
TreeNode* prevNode = &node;

void inorder(TreeNode* root) {
    if (root == nullptr)
        return;

    inorder(root->left);

    if (first == nullptr && prevNode->val > root->val) {
        first = prevNode;
    }

    if (first != nullptr && prevNode->val > root->val) {
        second = root;
    }

    prevNode = root;

    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    auto temp = first->val;
    first->val = second->val;
    second->val = temp;
}