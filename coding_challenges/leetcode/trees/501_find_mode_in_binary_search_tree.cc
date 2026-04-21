#include <vector>
#include <unordered_map>
#include "treenode.h"

void preorder(TreeNode* root, std::vector<int>& vec) {
    if (root == nullptr) return;

    vec.push_back(root->val);
    preorder(root->left, vec);
    preorder(root->right, vec);
}

vector<int> findMode(TreeNode* root) {
    std::unordered_map<int, int> m;

    std::vector<int> vec;

    preorder(root, vec);

    for (int num : vec) {
        if (m.count(num) > 0) {
            m[num] += 1;
        } else {
            m[num] = 1;
        }
    }

    int currentMaxCount = INT_MIN;
    vector<int> result;
    for (auto [key, val] : m) {
        if (val > currentMaxCount) {
            currentMaxCount = val;
        }
    }
    

    for (auto [key, val] : m) {
        if (val == currentMaxCount) {
            result.push_back(key);
        }
    }

    return result;
}