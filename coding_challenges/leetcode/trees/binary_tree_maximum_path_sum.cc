#include <iostream>
#include "treenode.h"

using namespace std;

int maxPath(TreeNode* node, int& m) {
    if (node == nullptr) return 0;

    int left = max(0, maxPath(node->left, m));
    int right = max(0, maxPath(node->right, m));

    m = max(m, left+right+node->val);
    return max(left, right) + node->val;
}

// maximum path sum of a binary tree
int maxPathSum(TreeNode* root) {
    if (root == nullptr) return 0;

    int maximum = INT_MIN;
    maxPath(root, maximum);
    return maximum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> nodes;

        while (cin.peek() != '\n' && cin.peek() != EOF) {
            int num;
            cin >> num;
            nodes.push_back(num);
        }
        
        cin.ignore();   

        if (!nodes.empty()) {  
            auto root = TreeNode::buildTree(nodes);
            cout << maxPathSum(root) << "\n";
        }
    }

    return 0;
}