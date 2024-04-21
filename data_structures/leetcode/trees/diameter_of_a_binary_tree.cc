#include <iostream>
#include <algorithm>
#include "treenode.h"

using namespace std;

int dfs(TreeNode* node, int& diameter) {
    if (node == nullptr) return 0;

    int left = dfs(node->left, diameter);
    int right = dfs(node->right, diameter);

    diameter = max(diameter, left + right);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;

    int diameter = 0;
    dfs(root, diameter);
    return diameter;
}

int main() {  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> nodes;
        int num;
        while (cin.peek() != '\n' && cin.peek() != EOF ) {
            cin >> num;
            nodes.push_back(num);
        }

        cin.ignore();

        if (!nodes.empty()) {
            auto root = TreeNode::buildTree(nodes);
            cout << diameterOfBinaryTree(root) << "\n";
        }
    }

    return 0;
}