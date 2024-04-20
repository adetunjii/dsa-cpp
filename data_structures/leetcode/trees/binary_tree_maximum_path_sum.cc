#include <iostream>
#include "treenode.h"

using namespace std;

class Solution {
public:
    int maximum = INT_MIN;

    int maxPath(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = max(0, maxPath(node->left));
        int right = max(0, maxPath(node->right));

        maximum = max(maximum, left+right+node->val);
        return max(left,right) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        maxPath(root);
        return maximum;
    }
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> input;

    int num;
    while(cin >> num) {
        input.push_back(num);
    }

    auto root = TreeNode::buildTree(input);

    Solution sol;

    cout << sol.maxPathSum(root) << endl;
    
    return 0;
}