#include <iostream>
#include <vector>
#include <stack>

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

class Solution {
private:
	std::vector<int> postorderIterative(Node* node) {
		std::vector<int> res;
		if (node == nullptr) return res;

		std::stack<Node*> st1;
		std::stack<Node*> st2;

		st1.push(node);

		while(!st1.empty()) {
			Node* top = st1.top();
			st2.push(top);
			st1.pop();

			for (auto n : top->children) {
				st1.push(n);
			}
		}

		while(!st2.empty()) {
			Node* t = st2.top();
			res.push_back(t->val);
			st2.pop();
		}

		return res;
	}

	void postorderRecursive(Node* node, std::vector<int>& res) {
		if (node == nullptr) return;

		for (auto child : node->children) {
			postorderRecursive(child, res);
		}

		res.push_back(node->val);
	}

public:
	std::vector<int> postorder(Node* root) {
		std::vector<int> res;
		postorderRecursive(root, res);
		return res;
	}

};