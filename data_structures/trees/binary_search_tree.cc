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
    bool isEmpty() {
        return size() == 0;
    }

    int size() {  return nodeCount; }

    // Add an element to the binary tree
    bool add(int elem) {
        
        // check to see if the value already exists in the tree.
        // If it does, ignore.
        if(contains(elem)) {
            return true;
        }

        root = add(root, elem);
        nodeCount += 1;
        return true;
    }

    TreeNode* add(TreeNode* node, int elem) {
        if (node == nullptr) {
            return new TreeNode(nullptr, nullptr, elem);
        }

        if (elem < node->data) {
            node->left = add(node->left, elem);
        } else if (elem > node->data) {
            node->right = add(node->right, elem);
        }

        return node;
    }

    bool remove(int elem) {
        if (contains(elem)) {
            root = remove(root, elem);
            nodeCount -= 1;
            return true;
        }

        return false;
    }

    TreeNode* remove(TreeNode* node, int elem) {
        if (node == nullptr) return nullptr;

        if (elem < node->data) {
            node->left = remove(node->left, elem);
        } else if (elem > node->data) {
            node->right = remove(node->right, elem);
        } else {
            // found node we want to remove
            if (node->left == nullptr) {
                return node->right;
            } else if (node->right == nullptr) {
                return node->left;
            } else {
                TreeNode* tmp = findMin(node->right);

                // swap the data
                node->data = tmp->data;

                node->right = remove(node->right, tmp->data);
            }
        }
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    TreeNode* findMax(TreeNode* node) {
        while(node->right != nullptr) node = node->right;
        return node;
    }

    bool contains(int elem) {
        if (root == nullptr) return false;
        return contains(root, elem);
    }

    bool contains(TreeNode* node, int elem) {

        // Base case: reached bottom, value not found
        if (node == nullptr) return false;

        if (elem < node->data) {
            return contains(node->left, elem);
        } else if (elem > node->data) {
            return contains(node->right, elem);
        }

        return true;
    }

    // Traversals
    std::vector<int> preOrderTraversalIterative() {
        std::vector<int> res;
        if (root == nullptr) return res;

        std::stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            auto top = st.top();
            st.pop();

            res.push_back(top->data);

            if (top->left != nullptr) st.push(top->left);
            if (top->right != nullptr) st.push(top->right);
        }
        return res;
    }

    std::vector<int> preOrderTraversal() {
        std::vector<int> res;
        preOrder(root, res);
        return res;
    }

    void preOrder(TreeNode* node, std::vector<int>& res) {
        if (node == nullptr) return;
        res.push_back(node->data);
        preOrder(node->left, res);
        preOrder(node->right, res);
    }

    std::vector<int> inOrderTraversal() {
        std::vector<int> res;
        inorder(root, res);
        return res;
    }

    void inorder(TreeNode* node, std::vector<int>& res) {
        if (node == nullptr) return;

        inorder(node->left, res);
        res.push_back(node->data);
        inorder(node->right, res);
    }

    std::vector<int> postOrderTraversal() {
        std::vector<int> res;
        postOrder(root, res);
        return res;
    }

    void postOrder(TreeNode* node, std::vector<int>& res) {
        if (node == nullptr) return;

        postOrder(node->left, res);
        postOrder(node->right, res);
        res.push_back(node->data);
    }

    std::vector<int> levelOrderTraversal() {
        std::vector<int> res;

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
