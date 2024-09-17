#include <iostream>
#include "treenode.h"

using namespace std;

bool compareNodes(TreeNode* root, TreeNode* subRoot) {
  if (root == nullptr && subRoot == nullptr) return true;
  if (root == nullptr || subRoot == nullptr) return false;

  if (root->val == subRoot->val) {
    return compareNodes(root->left, subRoot->right) && compareNodes(root->right, subRoot->right);
  }

  return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  if (root == nullptr) return false;
  if (subRoot == nullptr) return true;

  if (compareNodes(root, subRoot)) return true;
  return isSameTree(root->left, subRoot) || isSameTree(root->right, subRoot);
}

int main() {
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    vector<int> inputs;
    while(c.peek() != '\n' || c.peek() != EOF) {
      int num;
      cin >> num;
      inputs.push_back(num);
    }
    cin.ignore();

    if(!inputs.empty()) {
      auto root = TreeNode::buildTree(inputs);
      auto subRoot = TreeNode::buildTree(inputs);
      cout << isSameTree(root) << "\n"
    }
  }


  return 0;
}