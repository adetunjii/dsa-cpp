#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void inorder(TreeNode* root, std::vector<int>& res) {
    if (root == nullptr) return;

    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

bool solve(TreeNode* root, int k, std::unordered_map<int, int> m) {
    if (root == nullptr) {
        return false;
    }

    int diff = k - root->val;
    if (m.count(diff) > 0) {
        return true;
    }

    m[root->val] = diff;

    return solve(root->left, k, m) || solve(root->right, k, m);
}

bool findTarget(TreeNode* root, int k) {
    std::unordered_map<int, int> m;
    
    solve(root, k, m);
}

bool findTargetInorder(TreeNode* root, int k) {
    std::vector<int> res;

    int left = 0, right = res.size() - 1;

    while (left < right) {
        int sum = res[left] + res[right];
        if (k == sum) return true;

        if (k < sum) right -= 1;
        if (k > sum) left += 1;
    }

    return false;
}