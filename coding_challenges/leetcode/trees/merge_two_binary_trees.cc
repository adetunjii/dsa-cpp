#include <iostream>

class Solution {
private:
	TreeNode* merge(TreeNode* node1, TreeNode* node2) {
		if (node1 == nullptr && node2 == nullptr) return nullptr;
		if (node1 == nullptr && node2 != nullptr) {
			node1 = node2;
			return node1;
		}
		if (node1 != nullptr && node2 == nullptr) return node1;

		node1->val += node2->val;
		node1->left = merge(node1->left, node2->left);
		node1->right = merge(node1->right, node2->right);

		return node1;
	}
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		return merge(root1, root2);
	}
}