#ifndef NODE_H_
#define NODE_H_

#include <vector>
class Node {
public:
    int val;
    std : vect : or <Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
#endif // NODE_H_