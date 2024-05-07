#include <iostream>
#include <vector>
#include "../trees/treenode.h"

using namespace std;

vector<string> res;

void solve(TreeNode* node, string str) {
	if (node == nullptr) return;

	if (node->left == nullptr && node->right == nullptr) {
		str += to_string(node->val);
		res.push_back(str);
		return;
	}

	str += to_string(node->val);
	str += "->";
	solve(node->left, str);
	solve(node->right, str);
}

vector<string> binaryTreePaths(TreeNode* root) {
	solve(root, "");
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> nums;
		int num;
		while (cin.peek() != '\n' && cin.peek() != EOF) {
			cin >> num;
			nums.push_back(num);
		}
		cin.ignore();

		if(!nums.empty()) {
			TreeNode* root = TreeNode::buildTree(nums);

			auto res = binaryTreePaths(root);

			for (string s : res) {
				cout << s << "\n";
			}
		}
	}

	return 0;
}