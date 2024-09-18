#include <iostream>
#include <vector>
#include <stack>
#include <queue>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(TreeNode* left, TreeNode* right, int data) :   left(left),
                                                            right(right),
                                                            data(data)
    {}
};


class BinarySearchTree {
private:
    int nodeCount = 0;
    TreeNode* root = nullptr;
public:
    int size() {
        return nodeCount;
    }

    bool isEmpty() {
        return nodeCount == 0;
    }

    bool contains(int elem) {
        if (root == nullptr) return false;
        return contains(root, elem);
    }

    bool contains(TreeNode* node, int elem) {
        if (node == nullptr) return false;

        if (elem < node->data) {
            return contains(node->left, elem);
        } else if (elem > node->data) {
            return contains(node->right, elem);
        }

        return true;
    }

    bool add(int elem) {
        if (contains(elem)) return true;

        root = add(root, elem);
        nodeCount += 1;
        return true;
    }

    TreeNode* add(TreeNode* node, int elem) {
        if (node == nullptr) {
            return new TreeNode(nullptr, nullptr, elem);
        }

        if (elem < node->data) {
            node->left =  add(node->left, elem);
        } else if (elem > node->data) {
            node->right = add(node->right, elem);
        }

        return node;
    }

    bool remove(int elem) {
        if (!contains(elem)) return false;

        root = remove(root, elem);
        nodeCount -= 1;
        return true;
    }

    TreeNode* remove(TreeNode* node, int elem) {
        if (root == nullptr) return nullptr;

        if (elem < node->data) {
            node->left = remove(node->left, elem);
        } else if(elem > node->data) {
            node->right = remove(node->right, elem);
        } else {
            // we are at the node we want to remove.
            TreeNode* min = findMin(node->right);
            node->data = min->data;
            node->right = remove(node->right, min->data);
        }
    }

    TreeNode* findMin(TreeNode* node) {
        while(node != nullptr) node = node->left;
        return node;
    }

    TreeNode* findMax(TreeNode* node) {
        while(node != nullptr) node = node->right;
        return node;
    }

    //Traversals
    std::vector<int> preOrderTraversalRecursive() {
        std::vector<int> res;
        preOrder(root, res);
        return res;
    }

    void preOrder(TreeNode* node, std::vector<int>& res) {
        if (root == nullptr) return;

        res.push_back(root->data);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }

    std::vector<int> preOrderIterative() {
        std::vector<int> res;

        if (root == nullptr) return {};

        std::stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()) {
            auto top = st.top();
            st.pop();
            res.push_back(top->data);
            
            if(top->right) st.push(top->right);
            if (top->left) st.push(top->left); 
        }

        return res;
    }

    std::vector<int> inOrderIterative() {
        std::vector<int> res;
        if(root == nullptr) return {};

        std::stack<TreeNode*> st;
        auto current = root;

        while(!st.empty() || current != nullptr) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();

            res.push_back(current->data);
            current = current->right;
        }

        return res;
    }


    std::vector<int> postOrderIterative() {
        std::vector<int> res;
        if (root == nullptr) return {};

        std::stack<TreeNode*> st;
        auto current = root;
        TreeNode* lastVisited = nullptr;

        while(current != nullptr || !st.empty()) {
            while(current != nullptr) {
                current = current->left;
                st.push(current);
            }

            current = st.top();
            res.push_back(current->data);
            if (current->right != nullptr && lastVisited != current->right) {
                current = current->right;
            } else {
                lastVisited = current;
                st.pop();
            }
        }

        return res;
    }

    std::vector<int> levelOrderTraversal() {
        std::vector<int> res;
        if (root == nullptr) return {};

        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            res.push_back(front->data);

            if (front->left != nullptr) q.push(front->left);
            if (front->right != nullptr) q.push(front->right);
        }

        return res;
    }


};