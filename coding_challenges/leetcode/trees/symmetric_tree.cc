#include <iostream>

class Solution{
private isEqual(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr) return true;
	if (p == nullptr || q == nullptr) return false;

	if (p->val == q->val) {
		return isEqual(p->left, q->right) && isEqual(p->right, q->left);
	}

	return false;
}
public: 
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
	}	
}