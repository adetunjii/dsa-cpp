#include <stack>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void preorder(Node* root, std::vector<int>& res) {
    if (root == nullptr)
        return;

    res.push_back(root->val);

    for (auto child : root->children) {
        preorder(child, res);
    }
}

std::vector<int> preorderRecursive(Node* root) {
    std::vector<int> res;
    preorder(root, res);
    return res;
}

std::vector<int> preorderIterative(Node* root) {
    std::vector<int> res;
    std::stack<Node*> st;

    if (root == nullptr)
        return res;

    st.push(root);

    while (!st.empty()) {
        root = st.top();
        st.pop();
        res.push_back(root->val);

        for (auto it = root->children.rbegin(); it != root->children.rend(); it++) {
            st.push(*it);
        }
    }

    return res;
}