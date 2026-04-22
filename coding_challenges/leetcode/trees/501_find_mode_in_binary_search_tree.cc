#include <vector>
#include <unordered_map>
#include "treenode.h"

class FindMode {
public:
    int maxCount = 0;
    int count = 0;
    unordered_map<int, int> m;
    vector<int> result;
    TreeNode* node = nullptr;

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

    void inorderWithMap(TreeNode* root) {
        if (root == nullptr) return;

        inorderWithMap(root->left);

        if (m.count(root->val) > 0) {
            m[root->val] += 1;
        } else {
            m[root->val] = 1;
        }

        if (m[root->val] > maxCount) {
            result = {root->val};
            maxCount = m[root->val];
        } else if (m[root->val] == maxCount) {
            result.push_back(root->val);
        }

        inorderWithMap(root->right);
    }

    void inorderOptimal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorderOptimal(root->left);

        if (node == nullptr || node->val != root->val) {
            count = 1;
        } else {
            count += 1;
        }

        node == root;

        if (count > maxCount) {
            result = {root->val};
            maxCount = count;
        } else if (count == maxCount) {
            result.push_back(root->val);
        }

        inorderOptimal(root->right);
    }


    vector<int> findModeInOrder(TreeNode* root) {
        inorderOptimal(root);
        return result;
    }
};
