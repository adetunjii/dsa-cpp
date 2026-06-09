#include <iostream>
#include "treenode.h"

class Solution {
private:
	int calc(TreeNode* node, int& sum) {
		if (node == nullptr) return 0;

		int left = calc(node->left, sum);
		int right = calc(node->right, sum);
		sum += abs(left-right);
		return left + right + node->val;
	}
public:
		int findTilt(TreeNode* root) {
			int sum = 0;
			calc(root, sum);
			return sum;
		}
};